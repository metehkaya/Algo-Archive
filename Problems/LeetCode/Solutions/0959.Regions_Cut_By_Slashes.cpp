#define pb push_back

class Solution {
public:
    int n,N,ans;
    bool mark[3600];
    vector<int> adj[3600];
    int f(int i , int j , int k) {
        return 4*n*i+4*j+k;
    }
    void g(int i1 , int j1 , int k1 , int i2 , int j2 , int k2) {
        int x = f(i1,j1,k1);
        int y = f(i2,j2,k2);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    void dfs(int u) {
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v);
        }
    }
    int regionsBySlashes(vector<string>& ar) {
        n = ar.size();
        N = 4*n*n;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                char c = ar[i][j];
                if(c == ' ') {
                    g(i,j,0,i,j,1);
                    g(i,j,1,i,j,2);
                    g(i,j,2,i,j,3);
                    g(i,j,3,i,j,0);
                }
                else if(c == '/') {
                    g(i,j,0,i,j,3);
                    g(i,j,1,i,j,2);
                }
                else {
                    g(i,j,0,i,j,1);
                    g(i,j,2,i,j,3);
                }
            }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                if(i+1 < n)
                    g(i,j,2,i+1,j,0);
                if(j+1 < n)
                    g(i,j,1,i,j+1,3);
            }
        for( int i = 0 ; i < N ; i++ )
            if(!mark[i]) {
                ans++;
                dfs(i);
            }
        return ans;
    }
};