class Solution {
public:
    int n,k;
    int dp[30][2];
    int f(int idx , bool ok) {
        if(idx < 0)
            return 1;
        if(dp[idx][ok] != -1)
            return dp[idx][ok];
        dp[idx][ok] = 0;
        if(ok)
            dp[idx][ok] = f(idx-1,ok) + f(idx-2,ok);
        else {
            int bit = ((n & (1<<idx)) > 0);
            if(!bit)
                dp[idx][ok] = f(idx-1,ok);
            else {
                dp[idx][ok] = f(idx-1,true);
                if(idx-1 >= 0 && ((n & (1<<(idx-1))) > 0))
                    dp[idx][ok] += f(idx-2,true);
                else
                    dp[idx][ok] += f(idx-2,false);
            }
        }
        return dp[idx][ok];
    }
    int findIntegers(int n) {
        this->n = n;
        for( int i = 0 ; i < 30 ; i++ )
            if((1<<i) <= n)
                k = i;
            else
                break;
        memset(dp,-1,sizeof(dp));
        return f(k,false);
    }
};