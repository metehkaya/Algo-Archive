class Solution {
public:
    void dfs(int u , int& res , vector<vector<int>>& adj , vector<int>& quiet , vector<bool>& mark) {
        mark[u] = true;
        if(res == -1 or quiet[u] < quiet[res])
            res = u;
        for(int v : adj[u])
            if(!mark[v])
                dfs(v,res,adj,quiet,mark);
    }
    vector<int> loudAndRich(vector<vector<int>>& edges, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto e : edges)
            adj[e[1]].push_back(e[0]);
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            vector<bool> mark(n,false);
            int res = -1;
            dfs(i,res,adj,quiet,mark);
            ans.push_back(res);
        }
        return ans;
    }
};
