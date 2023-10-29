class Solution {
public:
    const int maxc = 15;
    int dfs(int u , int p , int c , int k , vector<int>& coins , vector<vector<int>>& adj , vector<vector<int>>& dp) {
        c = min(c,maxc-1);
        if(dp[u][c] != INT_MIN)
            return dp[u][c];
        int val = (coins[u] >> c);
        int dp1 = val-k , dp2 = val/2;
        for(int v : adj[u])
            if(v != p) {
                dp1 += dfs(v,u,c,k,coins,adj,dp);
                dp2 += dfs(v,u,c+1,k,coins,adj,dp);
            }
        return dp[u][c] = max(dp1,dp2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<vector<int>> dp(n,vector<int>(maxc,INT_MIN));
        return dfs(0,-1,0,k,coins,adj,dp);
    }
};
