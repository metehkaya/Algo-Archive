typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int unhappyFriends(int n, vii& ar, vii& pairs) {
        int ans = 0;
        vii pos(n,vi(n,-1));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n-1 ; j++ )
                pos[i][ar[i][j]] = j;
        for( int i = 0 ; i < n/2 ; i++ )
            for( int j = 0 ; j < 2 ; j++ ) {
                int x = pairs[i][j];
                int y = pairs[i][j^1];
                bool ok = false;
                for( int k = 0 ; k < n/2 ; k++ )
                    if(i != k)
                        for( int l = 0 ; l < 2 ; l++ ) {
                            int u = pairs[k][l];
                            int v = pairs[k][l^1];
                            if(pos[x][u] < pos[x][y] && pos[u][x] < pos[u][v])
                                ok = true;
                        }
                ans += ok;
            }
        return ans;
    }
};