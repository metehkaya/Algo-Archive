class Solution {
public:
    const int MX = 6001;
    int lastStoneWeightII(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(MX,false);
        int head = MX/2;
        dp[head] = true;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> dpnew(MX,false);
            for( int j = 0 ; j < MX ; j++ )
                if(dp[j])
                    dpnew[j-ar[i]] = dpnew[j+ar[i]] = true;
            dp = dpnew;
        }
        for( int i = 0 ; i <= head ; i++ )
            if(dp[head-i] || dp[head+i])
                return i;
        return -1;
    }
};