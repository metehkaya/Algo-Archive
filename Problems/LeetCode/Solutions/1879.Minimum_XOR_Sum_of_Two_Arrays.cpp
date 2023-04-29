class Solution {
public:
    int n;
    vector<int> a,b;
    int dp[(1<<14)];
    int f(int id , int bmask) {
        if(id == n)
            return 0;
        if(dp[bmask] != -1)
            return dp[bmask];
        dp[bmask] = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            if((bmask & (1<<i)) == 0)
                dp[bmask] = min(dp[bmask] , f(id+1,bmask|(1<<i)) + (a[id] ^ b[i]));
        return dp[bmask];
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        a = nums1;
        b = nums2;
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};