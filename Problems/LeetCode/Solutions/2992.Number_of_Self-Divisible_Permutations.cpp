class Solution {
public:
    int f(int idx , int n , int bmask , vector<int>& dp) {
        if(dp[bmask] != -1)
            return dp[bmask];
        if(idx == n)
            return 1;
        dp[bmask] = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(bmask & (1<<i))
                continue;
            int index = idx+1 , val = i+1;
            if(val % index == 0 or index % val == 0)
                dp[bmask] += f(idx+1,n,(bmask|(1<<i)),dp);
        }
        return dp[bmask];
    }
    int selfDivisiblePermutationCount(int n) {
        int N = (1 << n);
        vector<int> dp(N,-1);
        return f(0,n,0,dp);
    }
};
