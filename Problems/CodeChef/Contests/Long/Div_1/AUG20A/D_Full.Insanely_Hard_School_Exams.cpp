#include <bits/stdc++.h>
#define maxn 3001
#define pb push_back
using namespace std;
typedef long long LL;

LL total;
int T,n,m,k;
int cost[maxn];
LL dp[maxn][maxn];
vector<int> ar[maxn];
vector<int> red[maxn];

void reset() {
	total = 0;
	memset(dp,-1,sizeof(dp));
	for( int i = 1 ; i <= m ; i++ )
		ar[i].clear() , red[i].clear();
}

void input() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 , a,b,c ; i < n ; i++ ) {
		scanf("%d%d%d",&a,&b,&c);
		ar[c].pb(a);
	}
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d",&cost[i]);
}

void calc() {
	for( int i = 1 ; i <= m ; i++ ) {
		vector<int> v;
		sort(ar[i].begin(),ar[i].end());
		int sz = ar[i].size();
		for( int l = 0 , r = 0 ; r < sz ; l = r ) {
			while(r < sz && ar[i][l] == ar[i][r])
				r++;
			v.pb(r-l);
		}
		int vsz = v.size();
		if(vsz >= 3) {
			sort(v.begin(),v.end());
			reverse(v.begin(),v.end());
			int cnt1 = 0 , cnt2 = 0;
			for( int j = 0 ; j < vsz ; j++ ) {
				if(j >= 2)
					for( int t = 0 ; t < v[j] ; t++ )
						red[i].pb(cnt2);
				total += (LL) v[j] * cnt2;
				cnt2 += v[j] * cnt1;
				cnt1 += v[j];
			}
			reverse(red[i].begin(),red[i].end());
		}
	}
}

LL f(int col , int rem) {
	if(col == m+1)
		return 0;
	if(dp[col][rem] != -1)
		return dp[col][rem];
	dp[col][rem] = f(col+1,rem);
	int totalReduce = 0;
	int tempRem = rem-cost[col];
	for( int i = 0 ; i < red[col].size() && tempRem >= 0 ; i++ , tempRem -= cost[col] ) {
		totalReduce += red[col][i];
		dp[col][rem] = max( dp[col][rem] , f(col+1,tempRem) + totalReduce );
	}
	return dp[col][rem];
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		calc();
		printf("%lld\n",total-f(1,k));
	}
	return 0;
}
