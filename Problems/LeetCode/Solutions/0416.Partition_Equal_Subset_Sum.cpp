class Solution {
public:
    const static int maxs = 20001;
    bool dp[maxs];
    bool canPartition(vector<int>& ar) {
        int n = ar.size();
        memset(dp,false,sizeof(dp));
        int sum = 0;
        dp[0] = true;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = sum ; j >= 0 ; j-- )
                if(dp[j])
                    dp[j+ar[i]] = true;
            sum += ar[i];
        }
        return (sum%2 == 0) && dp[sum/2];
    }
};