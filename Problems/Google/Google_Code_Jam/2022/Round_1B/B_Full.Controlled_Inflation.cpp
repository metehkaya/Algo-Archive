#include <bits/stdc++.h>
#define maxp 103
#define maxn 1003
using namespace std;
typedef long long LL;

const LL BIG = (1LL << 62);

int T,n,p;
vector<LL> ar[maxn];
LL sum[maxn][maxp];
LL dp[maxn][maxp];

LL getCost(LL x , LL y , int id , int wh) {
	LL mn = ar[id][0];
	LL mx = ar[id][p-1];
	LL cost;
	if(x <= mn)
		cost = mx-x + mx-y;
	else if(x >= mx)
		cost = x-mn + y-mn;
	else if(x == y)
		cost = 2*(mx-mn);
	else if(x < y)
		cost = 2*(mx-mn) - (y-x);
	else
		cost = 2*(mx-mn) - (x-y);
	return cost;
}

LL f(int id , int wh) {
	if(id == n)
		return 0;
	if(dp[id][wh] != -1)
		return dp[id][wh];
	dp[id][wh] = BIG;
	LL x = ar[id][wh];
	for( int i = 0 ; i < p ; i++ ) {
		LL y = ar[id+1][i];
		LL cost = getCost(x,y,id+1,i);
		dp[id][wh] = min(dp[id][wh],f(id+1,i)+cost);
	}
	return dp[id][wh];
}

int main() {
	scanf("%d",&T);
	ar[0].push_back(0);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&p);
		for( int i = 1 ; i <= n ; i++ ) {
			ar[i].clear();
			for( int j = 0 ; j < p ; j++ ) {
				LL x;
				cin >> x;
				ar[i].push_back(x);
			}
			sort(ar[i].begin(),ar[i].end());
			for( int j = 1 ; j <= p ; j++ )
				sum[i][j] = sum[i][j-1] + ar[i][j-1];
		}
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %lld\n",tc,f(0,0));
	}
	return 0;
}
