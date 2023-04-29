class Solution {
public:
    int longestArithSeqLength(vector<int>& ar) {
        int n = ar.size() , ans = 2;
        map<int,int> dp[n];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < i ; j++ ) {
                int diff = ar[i] - ar[j];
                auto it = dp[j].find(diff);
                int val = (it == dp[j].end()) ? 1 : it->second;
                dp[i][diff] = max( dp[i][diff] , val+1 );
                ans = max(ans,val+1);
            }
        return ans;
    }
};