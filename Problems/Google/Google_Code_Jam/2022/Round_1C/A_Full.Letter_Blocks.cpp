#include <bits/stdc++.h>
#define maxn 100
#define pb push_back
using namespace std;

int T,n;
string ans;
string str[maxn];
int cnt[26];
int bef[26];
int last[26];
bool G[26][26];
int cntWord[maxn][26];
vector<int> adj[26];

void reset() {
	ans = "";
	memset(cnt,0,sizeof(cnt));
	memset(cntWord,0,sizeof(cntWord));
	memset(bef,0,sizeof(bef));
	memset(G,false,sizeof(G));
	for( int i = 0 ; i < 26 ; i++ )
		adj[i].clear();
}

void dfs(int u , int& total) {
	total++;
	for( int i = 0 ; i < cnt[u] ; i++ )
		ans.push_back('A'+u);
	if(adj[u].empty())
		return;
	dfs(adj[u][0],total);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		bool broken = false;
		for( int i = 0 ; i < n ; i++ ) {
			string s;
			cin >> s;
			str[i] = s;
			int len = s.length();
			memset(last,-1,sizeof(last));
			for( int j = 0 ; j < len ; j++ ) {
				int c = s[j]-'A';
				cnt[c]++;
				cntWord[i][c]++;
				if(j > 0 && last[c] != -1 && last[c] != j-1)
					broken = true;
				last[c] = j;
				if(j > 0 && s[j] != s[j-1])
					G[s[j-1]-'A'][s[j]-'A'] = true;
			}
		}
		for( int i = 0 ; i < 26 ; i++ ) {
			for( int j = 0 ; j < 26 ; j++ )
				if(G[i][j]) {
					adj[i].pb(j);
					bef[j]++;
					if(bef[j] > 1)
						broken = true;
				}
			if(adj[i].size() > 1)
				broken = true;
		}
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				if(i != j) {
					int comm = 0;
					for( int k = 0 ; k < 26 ; k++ )
						if(cntWord[i][k] && cntWord[j][k]) {
							comm++;
							int li = str[i].length();
							int lj = str[j].length();
							if(str[i][li-1] == str[j][0] || str[j][lj-1] == str[i][0])
								continue;
							else
								broken = true;
						}
					if(comm > 1)
						broken = true;
				}
		if(broken) {
			ans = "IMPOSSIBLE";
			printf("Case #%d: %s\n",tc,ans.c_str());
			continue;
		}
		int total = 0;
		vector<int> roots;
		for( int i = 0 ; i < 26 ; i++ )
			if(!bef[i])
				roots.pb(i);
		int r = roots.size();
		for( int i = 0 ; i < r ; i++ )
			dfs(roots[i],total);
		if(total != 26)
			ans = "IMPOSSIBLE";
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}
