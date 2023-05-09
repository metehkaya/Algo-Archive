#include <bits/stdc++.h>
#define pb push_back
#define maxn 200003
using namespace std;

int T,N,M,n,m;
int a[maxn];
int b[maxn];
int A[maxn];
int B[maxn];
int sum[maxn];

int solve() {
	if(n == 0 || m == 0)
		return 0;
	set<int> s;
	for( int i = 1 ; i <= n ; i++ )
		s.insert(a[i]);
	vector<int> v;
	for( int i = 1 ; i <= m ; i++ )
		v.push_back(b[i]);
	sum[m+1] = 0;
	for( int i = m ; i >= 1 ; i-- ) {
		sum[i] = sum[i+1];
		if(s.find(b[i]) != s.end())
			sum[i]++;
	}
	int maxscore = 0;
	for( int j = 1 , i = 0 ; j <= m ; j++ ) {
		while(i+1 <= n && a[i+1] <= b[j])
			i++;
		int score = sum[j+1];
		if(i) {
			vector<int>::iterator itr = upper_bound(v.begin(),v.end(),b[j]);
			vector<int>::iterator itl = lower_bound(v.begin(),v.end(),b[j]-(i-1));
			score += itr-itl;
		}
		maxscore = max(maxscore,score);
	}
	return maxscore;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&N,&M);
		for( int i = 1 ; i <= N ; i++ )
			scanf("%d",&A[i]);
		for( int i = 1 ; i <= M ; i++ )
			scanf("%d",&B[i]);
		n = m = 0;
		for( int i = 1 ; i <= N ; i++ )
			if(A[i] > 0)
				a[++n] = A[i];
		for( int i = 1 ; i <= M ; i++ )
			if(B[i] > 0)
				b[++m] = B[i];
		int scoreleft = solve();
		n = m = 0;
		for( int i = N ; i >= 1 ; i-- )
			if(A[i] < 0)
				a[++n] = -A[i];
		for( int i = M ; i >= 1 ; i-- )
			if(B[i] < 0)
				b[++m] = -B[i];
		int scoreright = solve();
		printf("%d\n",scoreleft+scoreright);
	}
	return 0;
}
