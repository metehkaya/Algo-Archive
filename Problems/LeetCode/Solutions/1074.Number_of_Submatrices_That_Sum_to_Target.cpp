class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& ar, int target) {
        int n = ar.size() , m = ar[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                dp[i][j] = dp[i-1][j] + ar[i-1][j-1];
        int ans = 0;
        for( int r1 = 1 ; r1 <= n ; r1++ )
            for( int r2 = r1 ; r2 <= n ; r2++ ) {
                int sum = 0;
                map<int,int> cnt;
                map<int,int>::iterator it;
                cnt[0] = 1;
                for( int i = 1 ; i <= m ; i++ ) {
                    sum += dp[r2][i] - dp[r1-1][i];
                    it = cnt.find(sum-target);
                    if(it != cnt.end())
                        ans += it->second;
                    cnt[sum]++;
                }
            }
        return ans;
    }
};