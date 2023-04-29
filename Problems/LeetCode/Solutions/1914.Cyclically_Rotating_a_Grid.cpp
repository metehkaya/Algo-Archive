#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& ar, int K) {
        int n = ar.size();
        int m = ar[0].size();
        for( int r1 = 0 , r2 = n-1 , c1 = 0 , c2 = m-1 ; r1 <= r2 && c1 <= c2 ; r1++ , r2-- , c1++ , c2-- ) {
            vector<pi> v;
            for( int i = c1 ; i < c2 ; i++ )
                v.pb(pi(r1,i));
            for( int i = r1 ; i < r2 ; i++ )
                v.pb(pi(i,c2));
            for( int i = c2 ; i > c1 ; i-- )
                v.pb(pi(r2,i));
            for( int i = r2 ; i > r1 ; i-- )
                v.pb(pi(i,c1));
            int len = v.size();
            int k = K % len;
            vector<int> vals;
            for( int i = 0 ; i < len ; i++ ) {
                pi p = v[i];
                int r = p.fi;
                int c = p.se;
                vals.pb(ar[r][c]);
            }
            for( int i = 0 ; i < len ; i++ ) {
                pi p = v[i];
                int r = p.fi;
                int c = p.se;
                ar[r][c] = vals[(i+k)%len];
            }
        }
        return ar;
    }
};