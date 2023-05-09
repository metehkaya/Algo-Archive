#include <bits/stdc++.h>
#define maxn 100003
#define maxv (27*27*27*27)
#define pb push_back
using namespace std;

int n,m,k;
int val[maxn];
int idx[maxv];
int indeg[maxn];
queue<int> Q;
vector<int> ids;
vector<int> ans;
vector<int> adj[maxn];

int getVal(char c) {
	if(c == '_')
		return 0;
	return c-'a' + 1;
}

void f(string& s , int i , int v) {
	if(i == k) {
		if(idx[v])
			ids.pb(idx[v]);
		return;
	}
	f(s,i+1,27*v);
	f(s,i+1,27*v+getVal(s[i]));
}

void imp() {
	puts("NO");
	exit(0);
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i++ ) {
		string s;
		cin >> s;
		int v = 0 , len = s.length();
		for( int j = 0 ; j < len ; j++ )
			v = 27*v + getVal(s[j]);
		val[i] = v;
		idx[v] = i;
	}
	for( int i = 1 ; i <= m ; i++ ) {
		int x;
		string s;
		cin >> s >> x;
		ids.clear();
		f(s,0,0);
		bool ok = false;
		int sz = ids.size();
		for( int j = 0 ; j < sz ; j++ )
			if(ids[j] == x)
				ok = true;
		if(!ok)
			imp();
		for( int j = 0 ; j < sz ; j++ )
			if(ids[j] != x) {
				int id = ids[j];
				adj[x].pb(id);
				indeg[id]++;
			}
	}
	for( int i = 1 ; i <= n ; i++ )
		if(!indeg[i])
			Q.push(i);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		ans.pb(u);
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(--indeg[v] == 0)
				Q.push(v);
		}
	}
	if(ans.size() != n)
		imp();
	puts("YES");
	for( int i = 0 ; i < n ; i++ )
		printf("%d ",ans[i]);
	puts("");
	return 0;
}
