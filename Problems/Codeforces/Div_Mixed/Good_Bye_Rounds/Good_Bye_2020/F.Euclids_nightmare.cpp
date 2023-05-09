#include <bits/stdc++.h>
#define maxn 500003
#define mod 1000000007
#define pb push_back
using namespace std;

int n,m,cnt;
int dad[maxn];
int lvl[maxn];
vector<int> edges;

int findDad(int u) {
	if(dad[u] == -1)
		return u;
	return dad[u] = findDad(dad[u]);
}

int main() {
	memset(dad,-1,sizeof(dad));
	scanf("%d%d",&m,&n);
	for( int i = 0 , k,u,v ; i < m ; i++ ) {
		v = 0;
		scanf("%d%d",&k,&u);
		if(k == 2)
			scanf("%d",&v);
		u = findDad(u);
		v = findDad(v);
		if(u != v) {
			cnt++;
			edges.pb(i+1);
			if(lvl[u] > lvl[v])
				swap(u,v);
			dad[u] = v;
			lvl[v] += (lvl[u] == lvl[v]);
		}
	}
	int ways = 1;
	for( int i = 0 ; i < cnt ; i++ )
		ways = (2*ways) % mod;
	printf("%d %d\n",ways,cnt);
	for( int i = 0 ; i < cnt ; i++ )
		printf("%d ",edges[i]);
	puts("");
	return 0;
}
