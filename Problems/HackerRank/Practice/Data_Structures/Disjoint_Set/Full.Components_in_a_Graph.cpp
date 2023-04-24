#include <bits/stdc++.h>
#define maxn 30001
#define pb push_back
using namespace std;

int n;
int sz[maxn];
int dad[maxn];
int lvl[maxn];

int findPar(int u) {
	if(u == dad[u])
		return u;
	return dad[u] = findPar(dad[u]);
}

void deal(int u , int v) {
	u = findPar(u);
	v = findPar(v);
	if(u == v)
		return;
	if(lvl[u] > lvl[v])
		swap(u,v);
	dad[u] = v;
	sz[v] += sz[u];
	if(lvl[u] == lvl[v])
		lvl[v]++;
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= 2*n ; i++ )
		sz[i] = 1 , dad[i] = i;
	for( int i = 1 , u,v ; i <= n ; i++ ) {
		scanf("%d%d",&u,&v);
		deal(u,v);
	}
	int mn = INT_MAX , mx = INT_MIN;
	for( int i = 1 ; i <= 2*n ; i++ )
		if(dad[i] == i && sz[i] > 1) {
			mn = min(mn,sz[i]);
			mx = max(mx,sz[i]);
		}
	printf("%d %d\n",mn,mx);
	return 0;
}
