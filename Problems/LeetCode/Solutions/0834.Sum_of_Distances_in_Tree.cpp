class Solution {
public:
    static const int maxn = 30000;
    int n;
    int sum[maxn];
    vector<int> ans;
    vector<int> adj[maxn];
    int dfs(int u , int dad , int lvl) {
        ans.push_back(0);
        ans[0] += lvl;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(v != dad)
                sum[u] += dfs(v,u,lvl+1);
        }
        return ++sum[u];
    }
    void solve(int u , int dad , int res) {
        ans[u] = res;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(v != dad)
                solve(v,u,res-sum[v]+(n-sum[v]));
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        for( int i = 0 ; i < n-1 ; i++ ) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,0);
        solve(0,-1,ans[0]);
        return ans;
    }
};