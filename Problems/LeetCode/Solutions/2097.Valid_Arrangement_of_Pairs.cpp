class Solution {
public:
    map<int,int> deg;
    map<int,vector<int>> adj;
    vector<vector<int>> ans;
    void dfs(int u) {
        vector<int>& vec = adj[u];
        while(!vec.empty()) {
            int v = vec.back();
            vec.pop_back();
            dfs(v);
            ans.push_back({u,v});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto& edge : pairs) {
            adj[edge[0]].push_back(edge[1]);
            deg[edge[0]]++;
            deg[edge[1]]--;
        }
        for( auto it = deg.begin() ; it != deg.end() ; it++ )
            if(it->second == 1)
                dfs(it->first);
        if(ans.empty())
            dfs(deg.begin()->first);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
