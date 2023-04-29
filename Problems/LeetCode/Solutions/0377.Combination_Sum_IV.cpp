typedef long long LL;

class Solution {
public:
    int n;
    LL dp[1001];
    int combinationSum4(vector<int>& ar, int m) {
        n = ar.size();
        dp[0] = 1;
        for( int i = 0 ; i < m ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(i+ar[j] <= m)
                    dp[i+ar[j]] = min(dp[i+ar[j]]+dp[i],(LL)INT_MAX);
        return (int) dp[m];
    }
};