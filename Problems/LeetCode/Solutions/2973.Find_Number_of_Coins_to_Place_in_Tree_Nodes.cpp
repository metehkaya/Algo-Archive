class Solution {
public:
    vector<int> dfs(int u , int dad , vector<vector<int>>& adj , vector<int>& cost , vector<long long>& ans) {
        vector<int> vals({cost[u]});
        for(int v : adj[u])
            if(v != dad) {
                vector<int> vals_new = dfs(v,u,adj,cost,ans);
                vals.insert(vals.end(), vals_new.begin(), vals_new.end());
            }
        sort(vals.begin(),vals.end());
        if(vals.size() > 5)
            vals.erase(vals.begin()+2,vals.end()-3);
        int n = vals.size();
        if(n < 3)
            ans[u] = 1;
        else {
            ans[u] = max(ans[u],(long long)vals[n-1]*vals[n-2]*vals[n-3]);
            ans[u] = max(ans[u],(long long)vals[n-1]*vals[0]*vals[1]);
        }
        return vals;
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<long long> ans(n,0);
        dfs(0,-1,adj,cost,ans);
        return ans;
    }
};
