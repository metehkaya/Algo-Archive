typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int MOD = 1000000007;
    void add( int x , int& sum ) {
        sum = (sum + x) % MOD;
    }
    int countVowelPermutation(int n) {
        vii dp( n , vi( 5 , 0 ) );
        for( int i = 0 ; i < 5 ; i++ )
            dp[0][i] = 1;
        for( int i = 0 ; i < n-1 ; i++ ) {
            add( dp[i][0] , dp[i+1][1] );
            add( dp[i][1] , dp[i+1][0] );
            add( dp[i][1] , dp[i+1][2] );
            add( dp[i][2] , dp[i+1][0] );
            add( dp[i][2] , dp[i+1][1] );
            add( dp[i][2] , dp[i+1][3] );
            add( dp[i][2] , dp[i+1][4] );
            add( dp[i][3] , dp[i+1][2] );
            add( dp[i][3] , dp[i+1][4] );
            add( dp[i][4] , dp[i+1][0] );
        }
        int ans = 0;
        for( int i = 0 ; i < 5 ; i++ )
            add( dp[n-1][i] , ans );
        return ans;
    }
};