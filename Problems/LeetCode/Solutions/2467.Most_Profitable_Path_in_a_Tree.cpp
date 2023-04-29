class Solution {
public:
    void dfs2(int u , int dad , int sum , int& ans , vector<int>& amount , vector<vector<int>>& adj) {
        sum += amount[u];
        for(int v : adj[u])
            if(v != dad)
                dfs2(v,u,sum,ans,amount,adj);
        if(u != 0 and adj[u].size() == 1)
            ans = max(ans,sum);
    }
    void dfs(int u , int dad , int depth , vector<int>& lvl , vector<int>& par , vector<vector<int>>& adj) {
        par[u] = dad;
        lvl[u] = depth;
        for(int v : adj[u])
            if(v != dad)
                dfs(v,u,depth+1,lvl,par,adj);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> lvl(n);
        vector<int> par(n);
        dfs(0,-1,0,lvl,par,adj);
        int u = bob;
        while(u != 0) {
            if(lvl[bob]-lvl[u] < lvl[u])
                amount[u] = 0;
            else if(lvl[bob]-lvl[u] == lvl[u])
                amount[u] /= 2;
            u = par[u];
        }
        int ans = INT_MIN;
        dfs2(0,-1,0,ans,amount,adj);
        return ans;
    }
};
