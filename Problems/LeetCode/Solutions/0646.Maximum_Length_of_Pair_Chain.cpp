class Solution {
public:
    int dp[2002];
    vector<int> v[2002];
    int findLongestChain(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            v[ar[i][0]+1000].push_back(ar[i][1]+1000);
        int ans = 0;
        for( int i = 0 ; i <= 2001 ; i++ ) {
            if(i)
                dp[i] = max(dp[i],dp[i-1]);
            ans = max(ans,dp[i]);
            int val = dp[i];
            int sz = v[i].size();
            for( int j = 0 ; j < sz ; j++ ) {
                int x = v[i][j]+1;
                dp[x] = max(dp[x],val+1);
            }
        }
        return ans;
    }
};