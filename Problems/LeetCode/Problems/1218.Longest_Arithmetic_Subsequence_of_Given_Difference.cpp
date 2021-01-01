class Solution {
public:
    int longestSubsequence(vector<int>& ar, int diff) {
        map<int,int> dp;
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int temp = 1 , val = ar[i];
            auto it = dp.find(val-diff);
            if(it != dp.end())
                temp = it->second + 1;
            int dpval = dp[val] = max(dp[val] , temp);
            ans = max(ans , dpval);
        }
        return ans;
    }
};