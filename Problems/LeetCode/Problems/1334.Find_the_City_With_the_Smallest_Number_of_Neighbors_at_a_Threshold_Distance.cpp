typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int findTheCity(int n, vii& edges, int maxDist) {
        int m = edges.size();
        vii G( n , vi( n , INT_MAX ) );
        for( int i = 0 ; i < n ; i++ )
            G[i][i] = 0;
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            G[u][v] = G[v][u] = d;
        }
        for( int k = 0 ; k < n ; k++ )
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    if( G[i][k] != INT_MAX && G[k][j] != INT_MAX )
                        G[i][j] = min( G[i][j] , G[i][k] + G[k][j] );
        int reach = n+1 , city = -1;
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            for( int j = 0 ; j < n ; j++ )
                if( G[i][j] <= maxDist )
                    cnt++;
            if(cnt <= reach) {
                reach = cnt;
                city = i;
            }
        }
        return city;
    }
};