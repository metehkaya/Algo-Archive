#include <bits/stdc++.h>
#define maxn 51
#define pb push_back
using namespace std;

int T,n,Q,root;
int ans[maxn];
int path[maxn];
bool mark[maxn];
vector<int> adj[maxn];
vector<int> nodes[maxn];

int dfs2(int u) {
	if(path[u])
		return path[u];
	path[u] = 1;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		path[u] = max(path[u],dfs2(v)+1);
	}
	return path[u];
}

void dfs(int u) {
	mark[u] = true;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(!mark[v])
			dfs(v);
	}
}

bool check(int src , int dest) {
	memset(mark,false,sizeof(mark));
	dfs(src);
	return mark[dest];
}

int ask(int x , int y , int z , bool isCheck) {
	if(isCheck) {
		if(check(z,y))
			return y;
		if(check(y,z))
			return z;
	}
	printf("%d %d %d\n",x,y,z);
	fflush(stdout);
	int m;
	scanf("%d",&m);
	return m;
}

void printAns() {
	for( int i = 1 ; i <= n ; i++ )
		ans[path[i]] = i;
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
	int res;
	scanf("%d",&res);
	if(res == -1)
		exit(0);
}

void mergeSort(vector<int>& vec , int l , int r) {
	if(l == r)
		return;
	int mid = (l+r) >> 1;
	mergeSort(vec,l,mid);
	mergeSort(vec,mid+1,r);
	vector<int> a,b;
	for( int i = l ; i <= mid ; i++ )
		a.pb(vec[i]);
	for( int i = mid+1 ; i <= r ; i++ )
		b.pb(vec[i]);
	int sza = mid-l+1;
	int szb = r-mid;
	vector<int> temp;
	int i = 0 , j = 0;
	while(i < sza && j < szb) {
		int med = ask(root,a[i],b[j],true);
		if(med == a[i]) {
			adj[b[j]].pb(a[i]);
			adj[a[i]].pb(root);
			temp.pb(a[i++]);
		}
		else {
			adj[a[i]].pb(b[j]);
			adj[b[j]].pb(root);
			temp.pb(b[j++]);
		}
	}
	while(i < sza)
		temp.pb(a[i++]);
	while(j < szb)
		temp.pb(b[j++]);
	int len = sza+szb;
	for( int i = 0 ; i < len ; i++ )
		vec[l+i] = temp[i];
}

void reset() {
	memset(path,0,sizeof(path));
	for( int i = 1 ; i <= n ; i++ ) {
		adj[i].clear();
		nodes[i].clear();
	}
}

int main() {
	scanf("%d%d%d",&T,&n,&Q);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		int x,y,z;
		int m = ask(1,2,3,false);
		if(m == 1)
			x = 2 , y = 1 , z = 3;
		else if(m == 2)
			x = 1 , y = 2 , z = 3;
		else
			x = 1 , y = 3 , z = 2;
		adj[z].pb(y);
		adj[y].pb(x);
		for( int i = 4 ; i <= n ; i++ ) {
			z = i;
			m = ask(x,y,z,false);
			int xx = x , yy = y , zz = z;
			if(m == x) {
				x = zz;
				y = xx;
				z = yy;
			}
			else if(m == y);
			else {
				y = zz;
				z = yy;
			}
			adj[z].pb(y);
			adj[y].pb(x);
		}
		root = x;
		for( int i = 1 ; i <= n ; i++ ) {
			dfs2(i);
			nodes[path[i]].pb(i);
		}
		vector<int> vec;
		for( int i = 2 ; i <= n ; i++ ) {
			int sz = nodes[i].size();
			for( int j = 0 ; j < sz ; j++ )
				vec.pb(nodes[i][j]);
		}
		mergeSort(vec,0,n-2);
		path[root] = 1;
		for( int i = 0 ; i < n-1 ; i++ )
			path[vec[i]] = 2+i;
		printAns();
	}
	return 0;
}
