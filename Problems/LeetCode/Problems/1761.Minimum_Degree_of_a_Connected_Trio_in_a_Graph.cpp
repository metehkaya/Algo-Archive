class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        int deg[n+1];
        bool e[n+1][n+1];
        memset(e,0,sizeof(e));
        memset(deg,0,sizeof(deg));
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(u != v) {
                deg[u]++ , deg[v]++;
                e[u][v] = e[v][u] = true;
            }
        }
        int ans = INT_MAX;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = i+1 ; j <= n ; j++ )
                for( int k = j+1 ; k <= n ; k++ )
                    if(e[i][j] && e[j][k] && e[k][i]) {
                        int sum = deg[i]+deg[j]+deg[k] - 6;
                        ans = min(ans,sum);
                    }
        return ans == INT_MAX ? -1 : ans;
    }
};