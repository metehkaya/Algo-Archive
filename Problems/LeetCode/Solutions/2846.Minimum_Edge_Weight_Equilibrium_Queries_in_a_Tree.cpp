class Solution {
public:
    static const int maxk = 17;
    static const int maxc = 26;
    static const int maxn = 10000;
    int lvl[maxn];
    int par[maxn][maxk];
    vector<int> cnt[maxn];
    vector<vector<int>> adj[maxn];
    void dfs(int u , int dad , int upcost) {
        lvl[u] = (dad == -1 ? 0 : lvl[dad]+1);
        cnt[u].resize(maxc,0);
        if(upcost != -1) {
            cnt[u] = cnt[dad];
            cnt[u][upcost]++;
        }
        par[u][0] = dad;
        for( int k = 1 ; k < maxk ; k++ )
            if(par[u][k-1] != -1) {
                int v = par[u][k-1];
                par[u][k] = par[v][k-1];
            }
        for(auto e : adj[u]) {
            int v = e[0] , w = e[1];
            if(v != dad)
                dfs(v,u,w);
        }
    }
    int lca(int u , int v) {
        if(lvl[u] < lvl[v])
            swap(u,v);
        int diff = lvl[u]-lvl[v];
        for( int k = 0 ; k < maxk ; k++ )
            if(diff & (1<<k))
                u = par[u][k];
        if(u == v)
            return u;
        int res = 0;
        for( int k = maxk-1 ; k >= 0 ; k-- )
            if(par[u][k] != -1) {
                if(par[u][k] == par[v][k])
                    res = par[u][k];
                else
                    u = par[u][k] , v = par[v][k];
            }
        return res;
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        memset(par,-1,sizeof(par));
        for(auto e : edges) {
            int u = e[0] , v = e[1] , w = e[2];
            adj[u].push_back({v,w-1});
            adj[v].push_back({u,w-1});
        }
        dfs(0,-1,-1);
        vector<int> ans;
        for(auto q : queries) {
            int u = q[0] , v = q[1];
            int l = lca(u,v);
            vector<int> total = cnt[u];
            transform(total.begin(), total.end(), cnt[v].begin(), total.begin(), std::plus<int>());
            transform(total.begin(), total.end(), cnt[l].begin(), total.begin(), std::minus<int>());
            transform(total.begin(), total.end(), cnt[l].begin(), total.begin(), std::minus<int>());
            int n_edges = accumulate(total.begin(), total.end(), 0);
            int mx = *max_element(total.begin(), total.end());
            ans.push_back(n_edges-mx);
        }
        return ans;
    }
};
