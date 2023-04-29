class Solution {
public:
    int n,total;
    bool f(int bmask , int sum , vector<int>& dp) {
        if(sum >= total)
            return false;
        if(dp[bmask] != -1)
            return dp[bmask];
        dp[bmask] = false;
        for( int i = 0 ; i < n ; i++ )
            if(bmask & (1<<i))
                if(!f(bmask^(1<<i),sum+i+1,dp))
                    dp[bmask] = true;
        return dp[bmask];
    }
    bool canIWin(int n, int total) {
        if(total == 0)
            return true;
        if(total > n*(n+1)/2)
            return false;
        this->n = n;
        this->total = total;
        vector<int> dp((1<<n),-1);
        return f((1<<n)-1,0,dp);
    }
};
