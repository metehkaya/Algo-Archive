typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    vi nums2vec( int i , int j , int k ) {
        vi vec(3);
        vec[0] = i;
        vec[1] = j;
        vec[2] = k;
        return vec;
    }
    vi num2vec( int val ) {
        vi vec(3);
        for( int i = 2 ; i >= 0 ; i-- ) {
            vec[i] = val % 3;
            val /= 3;
        }
        return vec;
    }
    int vec2num( vi& vec ) {
        int val = 0;
        for( int i = 0 ; i < 3 ; i++ ) {
            val *= 3;
            val += vec[i];
        }
        return val;
    }
    bool check( vi& a , vi& b ) {
        for( int i = 0 ; i < 3 ; i++ )
            if( a[i] == b[i] )
                return false;
        return true;
    }
    int numOfWays(int n) {
        vii vecs;
        for( int i = 0 ; i < 3 ; i++ )
            for( int j = 0 ; j < 3 ; j++ )
                for( int k = 0 ; k < 3 ; k++ )
                    if( i != j && j != k ) {
                        vi vec = nums2vec(i,j,k);
                        vecs.push_back(vec);
                    }
        int m = vecs.size();
        vii dp(n,vi(m,0));
        for( int i = 0 ; i < m ; i++ )
            dp[0][i] = 1;
        vii adj(m);
        for( int i = 0 ; i < m ; i++ ) {
            vi a = vecs[i];
            for( int j = 0 ; j < m ; j++ ) {
                vi b = vecs[j];
                if(check(a,b))
                    adj[i].push_back(j);
            }
        }
        for( int row = 1 ; row < n ; row++ )
            for( int i = 0 ; i < m ; i++ )
                for( int k = 0 ; k < adj[i].size() ; k++ ) {
                    int j = adj[i][k];
                    dp[row][i] = ( dp[row][i] + dp[row-1][j] ) % MOD;
                }
        int ans = 0;
        for( int i = 0 ; i < m ; i++ )
            ans = ( ans + dp[n-1][i] ) % MOD;
        return ans;
    }
};