class Solution {
public:
    int n;
    int cnt[50];
    int par[50];
    int dp[50][2];
    vector<int> price;
    vector<int> adj[50];
    void dfs(int u , int dad) {
        par[u] = dad;
        for(int v : adj[u])
            if(v != dad)
                dfs(v,u);
    }
    void addTrip(int u , int v) {
        vector<bool> mark(n,false);
        vector<int> v1,v2;
        while(u != -1) {
            mark[u] = true;
            v1.push_back(u);
            u = par[u];
        }
        while(!mark[v]) {
            v2.push_back(v);
            v = par[v];
        }
        for( int i = 0 ; i < v1.size() and v1[i] != v ; i++ )
            cnt[v1[i]]++;
        for(int u : v2)
            cnt[u]++;
        cnt[v]++;
    }
    int f(int u , int dad , bool ok) {
        if(dp[u][ok] != -1)
            return dp[u][ok];
        if(ok) {
            int val = cnt[u]*price[u]/2;
            for(int v : adj[u])
                if(v != dad)
                    val += f(v,u,false);
            dp[u][ok] = max(val,f(u,dad,false));
        }
        else {
            dp[u][ok] = 0;
            for(int v : adj[u])
                if(v != dad)
                    dp[u][ok] += f(v,u,true);
        }
        return dp[u][ok];
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        this->n = n;
        this->price = price;
        for(auto& e : edges)
            adj[e[0]].push_back(e[1]) , adj[e[1]].push_back(e[0]);
        memset(par,-1,sizeof(par));
        dfs(0,-1);
        for(auto& trip : trips)
            addTrip(trip[0],trip[1]);
        int total = 0;
        for( int i = 0 ; i < n ; i++ )
            total += price[i]*cnt[i];
        memset(dp,-1,sizeof(dp));
        return total - f(0,-1,true);
    }
};
