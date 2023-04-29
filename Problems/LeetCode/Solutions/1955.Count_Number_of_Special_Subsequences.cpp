class Solution {
public:
    int n;
    vector<int> ar;
    const int mod = (int) 1e9+7;
    static const int maxn = 100000;
    int dp[maxn][3];
    int f(int id , int k) {
        if(k == 3)
            return 1;
        if(id == n)
            return 0;
        if(dp[id][k] != -1)
            return dp[id][k];
        dp[id][k] = f(id+1,k);
        if(ar[id] == k) {
            dp[id][k] += f(id+1,k);
            dp[id][k] %= mod;
            dp[id][k] += f(id+1,k+1);
            dp[id][k] %= mod;
        }
        return dp[id][k];
    }
    int countSpecialSubsequences(vector<int>& ar) {
        n = ar.size();
        this-> ar = ar;
        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};