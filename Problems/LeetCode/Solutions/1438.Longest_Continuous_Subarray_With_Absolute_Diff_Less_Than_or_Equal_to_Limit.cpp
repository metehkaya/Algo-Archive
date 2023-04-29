typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int longestSubarray(vector<int>& ar, int limit) {
        int k = 0;
        int n = ar.size();
        vector<int> lg2(n+1,0);
        for( int i = 1 ; (1<<i) <= n ; i++ )
            k = lg2[1<<i] = i;
        for( int i = 3 ; i <= n ; i++ )
            if(lg2[i] == 0)
                lg2[i] = lg2[i-1];
        vii mn(k+1,vi(n));
        vii mx(k+1,vi(n));
        for( int i = 0 ; i < n ; i++ )
            mn[0][i] = mx[0][i] = ar[i];
        for( int j = 0 ; j < k ; j++ )
            for( int i = 0 ; i + (1<<(j+1)) <= n ; i++ ) {
                mn[j+1][i] = min( mn[j][i] , mn[j][i+(1<<j)] );
                mx[j+1][i] = max( mx[j][i] , mx[j][i+(1<<j)] );
            }
        int best = 1;
        for( int i = 0 ; i < n-best ; i++ ) {
            int l = i+best , r = n-1;
            while(l <= r) {
                int mid = (l+r) >> 1;
                int len = mid-i+1;
                int lg = lg2[len];
                int mnVal = min( mn[lg][i] , mn[lg][mid-(1<<lg)+1] );
                int mxVal = max( mx[lg][i] , mx[lg][mid-(1<<lg)+1] );
                if(mxVal - mnVal <= limit) {
                    l = mid+1;
                    best = len;
                }
                else
                    r = mid-1;
            }
        }
        return best;
    }
};