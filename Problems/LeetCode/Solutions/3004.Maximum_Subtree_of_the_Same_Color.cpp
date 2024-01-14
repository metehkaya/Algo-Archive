class Solution {
public:
    int dfs(int u , int dad , int& ans , vector<vector<int>>& adj , vector<int>& colors) {
        int sum = 1;
        for(int v : adj[u])
            if(v != dad) {
                int add = dfs(v,u,ans,adj,colors);
                if(colors[u] != colors[v] or sum == -1 or add == -1)
                    sum = -1;
                else
                    sum += add;
            }
        ans = max(ans,sum);
        return sum;
    }
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        dfs(0,-1,ans,adj,colors);
        return ans;
    }
};
