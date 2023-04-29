class Solution {
public:
    int t=0;
    static const int maxk = 10;
    static const int maxn = 1000;
    int dt[maxn];
    int ft[maxn];
    int lvl[maxn];
    int par[maxn][maxk];
    vector<int> adj[maxn];
    void dfs(int u , int dad , int depth) {
        lvl[u] = depth;
        dt[u] = ++t;
        par[u][0] = dad;
        for( int i = 1 ; i < maxk ; i++ )
            if(par[u][i-1] != -1)
                par[u][i] = par[par[u][i-1]][i-1];
        for(int v : adj[u])
            if(v != dad)
                dfs(v,u,depth+1);
        ft[u] = t;
    }
    int get_lca(int u , int v) {
        if(dt[u] <= dt[v] and ft[v] <= ft[u])
            return u;
        if(dt[v] <= dt[u] and ft[u] <= ft[v])
            return v;
        int lca = 0;
        for( int i = maxk-1 ; i >= 0 ; i-- ) {
            int tmp = par[u][i];
            if(tmp == -1)
                continue;
            if(dt[tmp] <= dt[v] and ft[v] <= ft[tmp])
                lca = tmp;
            else
                u = tmp;
        }
        return lca;
    }
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        memset(par,-1,sizeof(par));
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,0);
        vector<int> ans;
        for(auto& q : query) {
            int u = q[0] , v = q[1] , w = q[2];
            int l = get_lca(u,v);
            int l2 = get_lca(w,l);
            if(l != l2)
                ans.push_back(l);
            else if(dt[w] <= dt[l] and ft[l] <= ft[w])
                ans.push_back(l);
            else {
                int l_u = get_lca(u,w);
                int l_v = get_lca(v,w);
                if(lvl[l_u] < lvl[l_v])
                    swap(l_u,l_v);
                ans.push_back(l_u);
            }
        }
        return ans;
    }
};
