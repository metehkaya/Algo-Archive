typedef long long LL;

class Solution {
public:
    LL fixedRatio(string s, int n0, int n1) {
        int n = s.length() , k = n0+n1;
        if(k > n)
            return 0;
        vector<int> sum(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            sum[i+1] = sum[i] + (s[i] == '1');
        LL ans = 0;
        map<LL,int> dp[k];
        for( int i = 0 ; i < k ; i++ )
            dp[i][sum[i]] = 1;
        for( int i = k ; i <= n ; i++ ) {
            LL total = sum[i]-(LL)(i/k)*n1;
            ans += dp[i%k][total]++;
        }
        return ans;
    }
};
