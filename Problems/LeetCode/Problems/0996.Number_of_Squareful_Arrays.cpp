class Solution {
public:
    int numSquarefulPerms(vector<int>& ar) {
        int n = ar.size() , total = 0;
        vector<int> fact(n+1,1);
        for( int i = 1 ; i <= n ; i++ )
            fact[i] = fact[i-1]*i;
        int N = (1<<n);
        vector<vector<int>> dp(N,vector<int>(n,0));
        for( int bm = 1 ; bm < N ; bm++ )
            for( int i = 0 ; i < n ; i++ )
                if(bm & (1<<i)) {
                    if(bm == (1<<i))
                        dp[bm][i] = 1;
                    if(bm == N-1)
                        total += dp[bm][i];
                    for( int j = 0 ; j < n ; j++ )
                        if(!(bm & (1<<j))) {
                            int sum = ar[i] + ar[j];
                            int sq = sqrt(sum);
                            if(sq*sq != sum)
                                continue;
                            dp[bm|(1<<j)][j] += dp[bm][i];
                        }
                }
        sort(ar.begin(),ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            total /= fact[j-i];
        }
        return total;
    }
};