class Solution {
public:
    const static int maxn = (1<<15);
    int N,n;
    int dp[maxn];
    int f(int bmask , int k) {
        if(bmask == N-1)
            return 1;
        if(dp[bmask] != -1)
            return dp[bmask];
        dp[bmask] = 0;
        for( int i = 0 ; i < n ; i++ )
            if((bmask & (1<<i)) == 0)
                if((i+1)%k == 0 || k%(i+1) == 0)
                    dp[bmask] += f(bmask|(1<<i),k+1);
        return dp[bmask];
    }
    int countArrangement(int n) {
        N = (1<<n);
        this->n = n;
        memset(dp,-1,sizeof(dp));
        return f(0,1);
    }
};