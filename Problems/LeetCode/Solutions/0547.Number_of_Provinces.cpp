class Solution {
public:
    int n,ans;
    bool mark[200];
    vector<vector<int>> adj;
    void dfs(int u) {
        mark[u] = true;
        for( int i = 0 ; i < n ; i++ )
            if(adj[u][i] && !mark[i])
                dfs(i);
    }
    int findCircleNum(vector<vector<int>>& adj) {
        n = adj.size();
        this->adj = adj;
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                ans++;
                dfs(i);
            }
        return ans;
    }
};