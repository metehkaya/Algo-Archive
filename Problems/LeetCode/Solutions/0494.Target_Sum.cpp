class Solution {
public:
    int n,t;
    int dp[20][2001];
    vector<int> ar;
    const int INIT = 1000;
    int f(int id , int sum) {
        if(n == id)
            return sum == t;
        if(dp[id][sum] != -1)
            return dp[id][sum];
        dp[id][sum] = 0;
        dp[id][sum] += f(id+1,sum+ar[id]);
        dp[id][sum] += f(id+1,sum-ar[id]);
        return dp[id][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ar = nums;
        n = ar.size();
        t = target + INIT;
        memset(dp,-1,sizeof(dp));
        return f(0,INIT);
    }
};