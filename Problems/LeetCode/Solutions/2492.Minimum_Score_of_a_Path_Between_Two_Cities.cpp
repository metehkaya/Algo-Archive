class Solution {
public:
    void dfs(int u , int& ans, vector<bool>& mark, vector<vector<vector<int>>>& adj) {
        mark[u] = true;
        for(auto way : adj[u]) {
            int v = way[0];
            int w = way[1];
            ans = min(ans,w);
            if(!mark[v])
                dfs(v,ans,mark,adj);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(auto e : roads) {
            adj[e[0]-1].push_back(vector<int>({e[1]-1,e[2]}));
            adj[e[1]-1].push_back(vector<int>({e[0]-1,e[2]}));
        }
        vector<bool> mark(n,false);
        int ans = INT_MAX;
        dfs(0,ans,mark,adj);
        return ans;
    }
};
