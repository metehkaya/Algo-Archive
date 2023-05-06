#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int n,m;
int t[2];
int h[maxn];
int ar[maxn];
int dt[2][maxn];
int ft[2][maxn];
int par[2][maxn];
LL sum[2][maxn];
LL tree[2][maxn];
vector<int> adj[2][maxn];

void dfs(int k , int u , LL chain) {
	dt[k][u] = ++t[k];
	chain += ar[u];
	sum[k][u] = chain;
	for( int i = 0 ; i < adj[k][u].size() ; i++ )
		dfs(k,adj[k][u][i],chain);
	ft[k][u] = t[k];
}

void f(int k , int s , int e , int ch) {
	stack<int> st;
	for( int i = s ; i != e+ch ; i += ch ) {
		while(!st.empty() && h[st.top()] <= h[i])
			st.pop();
		if(!st.empty()) {
			par[k][i] = st.top();
			adj[k][st.top()].push_back(i);
		}
		st.push(i);
	}
	for( int i = s ; i != e+ch ; i += ch )
		if(!dt[k][i])
			dfs(k,i,0);
}

void update(int k , int i , int add) {
	while(i <= n) {
		tree[k][i] += add;
		i += (i&(-i));
	}
}

LL query(int k , int i) {
	LL total = 0;
	while(i) {
		total += tree[k][i];
		i -= (i&(-i));
	}
	return total;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&h[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	f(0,1,n,+1);
	f(1,n,1,-1);
	for( int i = 0 ; i < m ; i++ ) {
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if(t == 1) {
			int ch = b-ar[a];
			update(0,dt[0][a],+ch);
			update(0,ft[0][a]+1,-ch);
			update(1,dt[1][a],+ch);
			update(1,ft[1][a]+1,-ch);			
			ar[a] = b;
		}
		else {
			if(a == b)
				printf("%d\n",ar[a]);
			else {
				int k = (a < b) ? 0 : 1;
				if(dt[k][a] <= dt[k][b] && ft[k][b] <= ft[k][a]) {
					int dad = par[k][a];
					LL res = sum[k][b] - sum[k][dad];
					res += query(k,dt[k][b]);
					res -= query(k,dt[k][dad]);
					printf("%lld\n",res);
				}
				else
					puts("-1");
			}
		}
	}
	return 0;
}
