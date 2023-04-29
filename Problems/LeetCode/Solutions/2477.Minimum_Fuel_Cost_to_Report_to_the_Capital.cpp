class Solution {
public:
    long long ans = 0;
    long long dfs(int u, int dad, int k, vector<vector<int>>& adj) {
        long long sum = 1;
        for(int v : adj[u])
            if(v != dad)
                sum += dfs(v,u,k,adj);
        if(u)
            ans += (sum+k-1) / k;
        return sum;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int k) {
        int n = roads.size()+1;
        vector<vector<int>> adj(n);
        for(auto e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,k,adj);
        return ans;
    }
};
