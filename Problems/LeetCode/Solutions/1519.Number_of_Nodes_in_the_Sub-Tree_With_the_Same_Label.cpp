typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    void dfs(int u , int dad , vii& adj , string& labels , vii& cnt , vi& ans) {
        int c = labels[u]-'a';
        cnt[u][c]++;
        int sz = (int) adj[u].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int v = adj[u][i];
            if(v == dad)
                continue;
            dfs(v,u,adj,labels,cnt,ans);
            for( int i = 0 ; i < 26 ; i++ )
                cnt[u][i] += cnt[v][i];
        }
        ans[u] = cnt[u][c];
    }
    vi countSubTrees(int n, vii& edges, string labels) {
        vii adj(n);
        for( int i = 0 ; i < n-1 ; i++ ) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vi ans(n);
        vii cnt(n,vi(26,0));
        dfs(0,-1,adj,labels,cnt,ans);
        return ans;
    }
};