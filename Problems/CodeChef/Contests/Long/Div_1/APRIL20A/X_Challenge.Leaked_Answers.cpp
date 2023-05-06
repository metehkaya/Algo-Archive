#include <bits/stdc++.h>
#define fi first
#define se second
#define maxm 10
#define maxn 501
#define maxk 5001
#define pb push_back
using namespace std;
typedef vector<int> vi;

int T,n,m,k;
int ar[maxk][maxn];
int cpyAr[maxk][maxn];
int dp[maxk][maxn][maxm];
vector<vi> sols;
vector<vi> randvecs;

void output() {
	int nSols = sols.size();
	int bestSol = 0;
	for( int i = 1 ; i < nSols ; i++ )
		if( sols[i][0] > sols[bestSol][0] )
			bestSol = i;
	int randvecID = sols[bestSol][n+1];
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",sols[bestSol][randvecs[randvecID][i-1]]);
	puts("");
}

void calcScore(vector<int>& res) {
	res[0] = n+1;
	for( int i = 1 ; i <= k ; i++ ) {
		int score = 0;
		for( int j = 1 ; j <= n ; j++ )
			score += res[j] == ar[i][j];
		res[0] = min( res[0] , score );
	}
}

void fillRes(vector<int>& res, vector<int>& bestNums, bool randInGroup, int p, int row) {
	int sz = (int) bestNums.size();
	int bestNum = bestNums[rand()%sz];
	for( int i = p*row+1 ; i <= (p+1)*row ; i++ ) {
		if(randInGroup)
			bestNum = bestNums[rand()%sz];
		res[i] = bestNum;
	}
}

// Fill with the best scored number within each subgroup
void solve1(int g, int randvecID, bool randInGroup) {
	vector<int> res(n+2);
	int row = n/g;
	for( int p = 0 ; p < g ; p++ ) {
		int bestScore = -1;
		vector<int> bestNums;
		for( int num = 1 ; num <= m ; num++ ) {
			int numsBestScore = row+1;
			for( int i = 1 ; i <= k ; i++ ) {
				int score = dp[i][(p+1)*row][num] - dp[i][p*row][num];
				numsBestScore = min(numsBestScore , score);
			}
			if(numsBestScore > bestScore) {
				bestScore = numsBestScore;
				bestNums.clear();
				bestNums.pb(num);
			}
			else if(numsBestScore == bestScore)
				bestNums.pb(num);
		}
		fillRes(res, bestNums, randInGroup, p, row);
	}
	calcScore(res);
	res[n+1] = randvecID;
	sols.pb(res);
}

// Fill with the most frequent number within each subgroup
void solve2(int g, int randvecID, bool randInGroup) {
	vector<int> res(n+2);
	int row = n/g;
	for( int p = 0 ; p < g ; p++ ) {
		int cnt[m+1];
		memset(cnt, 0, sizeof(cnt));
		for( int i = 1 ; i <= k ; i++ ) {
			if(row <= m)
				for( int j = p*row+1 ; j <= (p+1)*row ; j++ )
					cnt[ ar[i][j] ]++;
			else
				for( int j = 1 ; j <= m ; j++ )
					cnt[j] += dp[i][(p+1)*row][j] - dp[i][p*row][j];
		}
		int bestCnt = -1;
		vector<int> bestNums;
		for( int i = 1 ; i <= m ; i++ ) {
			if(cnt[i] > bestCnt) {
				bestCnt = cnt[i];
				bestNums.clear();
				bestNums.pb(i);
			}
			else if(cnt[i] == bestCnt)
				bestNums.pb(i);
		}
		fillRes(res, bestNums, randInGroup, p, row);
	}
	calcScore(res);
	res[n+1] = randvecID;
	sols.pb(res);
}

void trySols(int randvecID) {
	for( int i = 1 ; i <= n ; i++ )
		if( n % i == 0 ) {
			if(i < n) {
				solve1(i,randvecID,false);
				solve1(i,randvecID,true);
			}
			solve2(i,randvecID,false);
			solve2(i,randvecID,true);
		}
}

void calcDP() {
	memset(dp, 0, sizeof(dp));
	for( int i = 1 ; i <= k ; i++ )
		for( int j = 1 ; j <= n ; j++ ) {
			for( int l = 1 ; l <= m ; l++ )
				dp[i][j][l] = dp[i][j-1][l];
			dp[i][j][ar[i][j]]++;
		}
}

void shuffleInput() {
	vi randvec;
	for( int i = 1 ; i <= n ; i++ )
		randvec.pb(i);
	for( int i = 0 ; i < 10 ; i++ )
		random_shuffle( randvec.begin() , randvec.end() );
	randvecs.pb(randvec);
	for( int i = 1 ; i <= k ; i++ )
		for( int j = 1 ; j <= n ; j++ )
			ar[i][randvec[j-1]] = cpyAr[i][j];
}

void init() {
	sols.clear();
	randvecs.clear();
	vi randvec;
	for( int i = 1 ; i <= n ; i++ )
		randvec.pb(i);
	randvecs.pb(randvec);
	for( int i = 1 ; i <= k ; i++ )
		for( int j = 1 ; j <= n ; j++ )
			cpyAr[i][j] = ar[i][j];
}

void sol() {
	init();
	calcDP();
	trySols(0);
	for( int i = 1 ; i <= 3 ; i++ ) {
		shuffleInput();
		calcDP();
		trySols(i);
	}
	output();
}

int main() {
	srand(time(NULL));
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&n,&m,&k);
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= k ; j++ )
				scanf("%d",&ar[j][i]);
		sol();
	}
	return 0;
}
