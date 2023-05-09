#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 5001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n;
int ar[maxn];
bool mark[maxn];
vector<pi> ans;

void dfs(int u) {
	mark[u] = true;
	for( int i = 1 ; i <= n ; i++ )
		if(!mark[i] && ar[u] != ar[i]) {
			ans.pb(pi(u,i));
			dfs(i);
		}
}

void reset() {
	ans.clear();
	for( int i = 1 ; i <= n ; i++ )
		mark[i] = false;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		bool same = true;
		for( int i = 2 ; i <= n ; i++ )
			if(ar[1] != ar[i])
				same = false;
		if(same)
			puts("NO");
		else {
			reset();
			puts("YES");
			dfs(1);
			for( int i = 1 ; i < n ; i++ )
				printf("%d %d\n",ans[i-1].fi,ans[i-1].se);
		}
	}
	return 0;
}
