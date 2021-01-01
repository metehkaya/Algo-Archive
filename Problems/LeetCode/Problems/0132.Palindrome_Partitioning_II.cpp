class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> v[n];
        for( int i = 0 ; i < n ; i++ ) {
            int l = i , r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                v[l].push_back(r);
                l-- , r++;
            }
        }
        for( int i = 0 ; i+1 < n ; i++ ) {
            int l = i , r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                v[l].push_back(r);
                l-- , r++;
            }
        }
        int dp[n+1];
        dp[n] = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            dp[i] = INT_MAX;
            int sz = v[i].size();
            for( int k = 0 ; k < sz ; k++ ) {
                int j = v[i][k];
                dp[i] = min(dp[i],dp[j+1]+1);
            }
        }
        return dp[0]-1;
    }
};