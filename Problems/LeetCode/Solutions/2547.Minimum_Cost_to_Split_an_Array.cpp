class Solution {
public:
    int minCost(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int add = 0;
            vector<int> cnt(n,0);
            for( int j = i ; j < n ; j++ ) {
                if(++cnt[v[j]] == 2)
                    add += 2;
                else if(cnt[v[j]] > 2)
                    add++;
                dp[i] = min(dp[i],dp[j+1]+add+k);
            }
        }
        return dp[0];
    }
};
