class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(n,1);
        vector<int> bef(n,-1);
        sort(ar.begin() , ar.end());
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < i ; j++ )
                if(ar[i] % ar[j] == 0 && dp[j] + 1 > dp[i]) {
                    bef[i] = j;
                    dp[i] = dp[j] + 1;
                }
        int best = -1;
        for( int i = 0 ; i < n ; i++ )
            if(best == -1 || dp[i] > dp[best])
                best = i;
        vector<int> ans;
        while(best != -1) {
            ans.push_back(ar[best]);
            best = bef[best];
        }
        return ans;
    }
};