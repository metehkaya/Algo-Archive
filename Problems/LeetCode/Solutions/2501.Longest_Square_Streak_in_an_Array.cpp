const int MAXV = 100003;

class Solution {
public:
    int dp[MAXV+1];
    int longestSquareStreak(vector<int>& v) {
        int n = v.size() , ans = 0;
        sort(v.begin(),v.end());
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int num = v[i];
            dp[num] = max(dp[num],1);
            if(num <= MAXV/num)
                dp[num] = max(dp[num],dp[num*num]+1);
            ans = max(ans,dp[num]);
        }
        return ans >= 2 ? ans : -1;
    }
};
