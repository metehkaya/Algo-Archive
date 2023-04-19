#include <bits/stdc++.h>
#define maxn 16
#define maxbm (1<<maxn)
#define pb push_back
using namespace std;
typedef long long LL;

int n;
LL dp[maxbm];
LL sum[maxbm];
int a[maxn][maxn];
vector<int> nextGroups[maxbm];

void input() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			scanf("%d",&a[i][j]);
}

void findNextGroups(int bmask, int id, int curr, vector<int>& v) {
	if(id == (int) v.size()) {
		if(curr != 0)
			nextGroups[bmask].pb(curr);
		return;
	}
	findNextGroups(bmask, id+1, curr, v);
	findNextGroups(bmask, id+1, curr | (1 << v[id]), v);
}

void calcGroups() {
	for( int bm = 0 ; bm < (1<<n) ; bm++ ) {
		vector<int> v1, v0;
		for( int i = 0 ; i < n ; i++ )
			if( bm & (1<<i) )
				v1.pb(i);
			else
				v0.pb(i);
		for( int i = 0 ; i < (int) v1.size() ; i++ )
			for( int j = i+1 ; j < (int) v1.size() ; j++ )
				sum[bm] += a[v1[i]][v1[j]];
		findNextGroups(bm, 0, 0, v0);
	}
}

LL f(int bmask) {
	if(bmask == (1<<n)-1)
		return 0;
	if(dp[bmask] != -1)
		return dp[bmask];
	dp[bmask] = 0;
	for( int i = 0 ; i < (int) nextGroups[bmask].size() ; i++ ) {
		int nextGroup = nextGroups[bmask][i];
		dp[bmask] = max( dp[bmask] , f(bmask | nextGroup) + sum[nextGroup] );
	}
	return dp[bmask];
}

void solve() {
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",f(0));
}

int main() {
	input();
	calcGroups();
	solve();
	return 0;
}
