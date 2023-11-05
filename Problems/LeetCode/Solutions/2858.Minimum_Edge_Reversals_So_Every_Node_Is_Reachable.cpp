class Solution {
public:
    static const int maxn = 100003;
    vector<int> adj[maxn][2];
    void dfs(int u , int dad , vector<int>& ans) {
        for( int k = 0 ; k < 2 ; k++ )
            for(int v : adj[u][k])
                if(v != dad) {
                    ans[0] += k;
                    dfs(v,u,ans);
                }
    }
    void solve(int u , int dad , vector<int>& ans) {
        for( int k = 0 ; k < 2 ; k++ )
            for(int v : adj[u][k])
                if(v != dad) {
                    ans[v] = ans[u] + (k == 0 ? 1 : -1);
                    solve(v,u,ans);
                }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        for(auto& e : edges) {
            adj[e[0]][0].push_back(e[1]);
            adj[e[1]][1].push_back(e[0]);
        }
        vector<int> ans(n,0);
        dfs(0,-1,ans);
        solve(0,-1,ans);
        return ans;
    }
};
