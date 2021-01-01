class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size();
        vector<vector<int>> dp( G+1 , vector<int>( P+1 , 0 ) );
        dp[0][0] = 1;
        for( int item = 0 ; item < n ; item++ )
            for( int i = G - group[item] ; i >= 0 ; i-- )
                for( int j = P ; j >= 0 ; j-- ) {
                    int a = i + group[item];
                    int b = min( j + profit[item] , P );
                    dp[a][b] = ( dp[a][b] + dp[i][j] ) % MOD;
                }
        int ans = 0;
        for( int i = 0 ; i <= G ; i++ )
            ans = ( ans + dp[i][P] ) % MOD;
        return ans;
    }
};