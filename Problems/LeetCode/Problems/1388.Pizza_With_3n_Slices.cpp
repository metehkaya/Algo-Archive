class Solution {
public:
    int f(int index, int k, int e, vector<int>& ar, vector<vector<int>>& dp) {
        if(k == -1)
            return 0;
        if(index > e)
            return -2;
        if(dp[index][k] != -1)
            return dp[index][k];
        int val;
        dp[index][k] = -2;
        val = f(index+1,k,e,ar,dp);
        if(val != -2)
            dp[index][k] = max(dp[index][k], val);
        val = f(index+2,k-1,e,ar,dp);
        if(val != -2)
            dp[index][k] = max(dp[index][k], val+ar[index]);
        return dp[index][k];
    }
    int solve(vector<int>& ar, int n, int s, int e) {
        vector<vector<int>> dp(n,vector<int>(n/3,-1));
        return f(s,n/3-1,e,ar,dp);
    }
    int maxSizeSlices(vector<int>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int ans = 0;
        ans = max(ans, solve(ar,n,0,n-2));
        ans = max(ans, solve(ar,n,1,n-1));
        return ans;
    }
};