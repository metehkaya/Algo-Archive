class Solution {
public:
    int n,N;
    int g[14][14];
    int dp[1<<14];
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    int f(int bmask , int k) {
        if(bmask == N)
            return 0;
        if(dp[bmask])
            return dp[bmask];
        for( int i = 0 ; i < n ; i++ )
            if((bmask&(1<<i)) == 0)
                for( int j = 0 ; j < n ; j++ )
                    if((bmask&(1<<j)) == 0)
                        if(i != j)
                            dp[bmask] = max(dp[bmask],k*g[i][j]+f(bmask+(1<<i)+(1<<j),k+1));
        return dp[bmask];
    }
    int maxScore(vector<int>& ar) {
        n = ar.size();
        N = (1<<n)-1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                g[i][j] = gcd(ar[i],ar[j]);
        memset(dp,0,sizeof(dp));
        return f(0,1);
    }
};