typedef vector<int> vi;
typedef vector<vi> vii;

class TreeAncestor {
public:
    vii adj;
    vii par;
    const int K = 16;
    void dfs(int u , int dad) {
        par[u][0] = dad;
        for( int i = 1 ; i < 16 ; i++ )
            if(par[u][i-1] != -1)
                par[u][i] = par[par[u][i-1]][i-1];
        int sz = adj[u].size();
        for( int i = 0 ; i < sz ; i++ )
            dfs(adj[u][i] , u);
    }
    TreeAncestor(int n, vector<int>& parent) {
        adj.resize(n);
        par.resize(n,vi(K,-1));
        for( int i = 1 ; i < n ; i++ )
            adj[parent[i]].push_back(i);
        dfs(0,-1);
    }
    int getKthAncestor(int u, int k) {
        for( int i = K-1 ; u != -1 && i >= 0 ; i-- )
            if(k & (1<<i))
                u = par[u][i];
        return u;
    }
};