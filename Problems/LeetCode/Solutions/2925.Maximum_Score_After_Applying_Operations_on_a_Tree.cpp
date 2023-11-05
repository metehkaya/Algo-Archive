class Solution {
public:
    static const int maxn = 20003;
    long long dp[maxn][2];
    long long dfs(int u , int dad , bool ok , vector<vector<int>>& adj , vector<int>& values) {
        if(dp[u][ok] != -1)
            return dp[u][ok];
        vector<int> children;
        for(int v : adj[u])
            if(v != dad)
                children.push_back(v);
        dp[u][ok] = 0;
        for(int v : children)
            dp[u][ok] += dfs(v,u,true,adj,values);
        if(ok or !children.empty()) {
            long long val = values[u];
            for(int v : children)
                val += dfs(v,u,ok,adj,values);
            dp[u][ok] = max(dp[u][ok],val);
        }
        return dp[u][ok];
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        memset(dp,-1,sizeof(dp));
        return dfs(0,-1,false,adj,values);
    }
};
