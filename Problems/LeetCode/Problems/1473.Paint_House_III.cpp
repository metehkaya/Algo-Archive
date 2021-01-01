typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution {
public:
    int minCost(vector<int>& ar, vector<vector<int>>& cost, int n, int m, int target) {
        viii dp(n+1,vii(n+1,vi(m+1,INT_MAX)));
        dp[0][0][0] = 0;
        for( int city = 0 ; city < n ; city++ )
            for( int diff = 0 ; diff < n ; diff++ )
                for( int last = 0 ; last <= m ; last++ )
                    if( dp[city][diff][last] != INT_MAX ) {
                        int city2 = city+1;
                        if(ar[city]) {
                            int diff2 = diff + (ar[city] != last);
                            int last2 = ar[city];
                            int val = dp[city][diff][last];
                            int dp2 = dp[city2][diff2][last2];
                            dp[city2][diff2][last2] = min( val , dp2 );
                        }
                        else {
                            for( int last2 = 1 ; last2 <= m ; last2++ ) {
                                int diff2 = diff + (last2 != last);
                                int val = dp[city][diff][last] + cost[city][last2-1];
                                int dp2 = dp[city2][diff2][last2];
                                dp[city2][diff2][last2] = min( val , dp2 );
                            }
                        }
                    }
        int ans = INT_MAX;
        for( int i = 1 ; i <= m ; i++ )
            ans = min( ans , dp[n][target][i] );
        return (ans == INT_MAX) ? -1 : ans;
    }
};