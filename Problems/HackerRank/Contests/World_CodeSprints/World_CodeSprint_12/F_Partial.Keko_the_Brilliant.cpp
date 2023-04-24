#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;

int n,k;
int r[maxn];
set<int> myset;
map<int,int> hashh;
vector<int> dp[maxn];
vector<int> adj[maxn];

int f(int node , int dad , int mn) {
	if(dp[node][mn] != -1)
		return dp[node][mn];
	int sum1 = 0 , sum2 = 0;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if(adj[node][i] != dad) {
			sum1 += f(adj[node][i],node,r[node]);
			sum2 += f(adj[node][i],node,mn);
		}
	if(r[node] < mn)
		dp[node][mn] = sum2+1;
	else
		dp[node][mn] = min(sum1,sum2+1);
	return dp[node][mn];
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&r[i]);
		myset.insert(r[i]);
	}
	set<int>::iterator it = myset.begin();
	while(it != myset.end()) {
		hashh[(*it)] = k++;
		it++;
	}
	for( int i = 1 ; i <= n ; i++ )
		r[i] = hashh[r[i]];
	for( int i = 1 , x , y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 0 ; j < k ; j++ )
			dp[i].pb(-1);
	printf("%d\n",f(1,0,0));
	return 0;
}
