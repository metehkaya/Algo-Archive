class Solution {
public:
    static const int maxn = 100003;
    int n,t;
    int dt[maxn];
    int ft[maxn];
    int idx[maxn];
    vector<int> ans;
    vector<int> adj[maxn];
    void dfs(int u , int dad) {
        dt[u] = ++t;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(adj[u][i],u);
        ft[u] = ++t;
    }
    int solve(int u , int dad) {
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            ans[u] = max(ans[u],solve(adj[u][i],u));
        return ans[u];
    }
    vector<int> smallestMissingValueSubtree(vector<int>& dad, vector<int>& ar) {
        n = dad.size();
        for( int i = 1 ; i < n ; i++ )
            adj[dad[i]].push_back(i);
        dfs(0,-1);
        ans.resize(n,1);
        memset(idx,-1,sizeof(idx));
        for( int i = 0 ; i < n ; i++ )
            idx[ar[i]] = i;
        int u = idx[1];
        if(u != -1) {
            ans[u] = 2;
            for( int i = 2 ; i < maxn && idx[i] != -1 ; i++ ) {
                int v = idx[i];
                while(!(dt[u] <= dt[v] && ft[v] <= ft[u]))
                    u = dad[u];
                ans[u] = i+1;
            }
        }
        solve(0,-1);
        return ans;
    }
};