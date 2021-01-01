typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int K = 40;
    const int MOD = (int)1e9 + 7;
    int f( int hat , int bmask , int n , vii& ar , vii& dp ) {
        if(hat == K)
            return bmask == (1<<n)-1;
        if(dp[hat][bmask] != -1)
            return dp[hat][bmask];
        dp[hat][bmask] = f( hat+1 , bmask , n , ar , dp );
        for( int i = 0 ; i < ar[hat].size() ; i++ ) {
            int v = ar[hat][i];
            if( bmask & (1<<v) )
                continue;
            dp[hat][bmask] = ( dp[hat][bmask] + f( hat+1 , bmask | (1<<v) , n , ar , dp ) ) % MOD;
        }
        return dp[hat][bmask];
    }
    int numberWays(vii& hats) {
        int n = hats.size();
        vii ar(K);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < hats[i].size() ; j++ )
                ar[hats[i][j] - 1].push_back(i);
        vii dp( K , vi(1<<n , -1) );
        return f( 0 , 0 , n , ar , dp );
    }
};