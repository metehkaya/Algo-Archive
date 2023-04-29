class Solution {
public:
    int n,m,N,dfs_cnt;
    int dfs(int u , int p , vector<vector<int>>& g , vector<int>& mark) {
        mark[u] = dfs_cnt;
        if(u == N-1)
            return p;
        for( int v = 0 ; v < N ; v++ ) {
            if(mark[v] == dfs_cnt || !g[u][v])
                continue;
            int w = min(p,g[u][v]);
            w = dfs(v,w,g,mark);
            if(w) {
                g[u][v] -= w;
                g[v][u] += w;
                return w;
            }
        }
        return 0;
    }
    int maximumInvitations(vector<vector<int>>& v) {
        n = v.size() , m = v[0].size();
        N = n+m+2;
        vector<vector<int>> g(N,vector<int>(N,0));
        for( int i = 0 ; i < n ; i++ )
            g[0][1+i] = 1;
        for( int j = 0 ; j < m ; j++ )
            g[1+n+j][N-1] = 1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                g[1+i][1+n+j] = v[i][j];
        vector<int> mark(N,0);
        int ans = 0;
        while(true) {
            dfs_cnt++;
            int p = dfs(0,INT_MAX,g,mark);
            if(p == 0)
                break;
            ans += p;
        }
        return ans;
    }
};
