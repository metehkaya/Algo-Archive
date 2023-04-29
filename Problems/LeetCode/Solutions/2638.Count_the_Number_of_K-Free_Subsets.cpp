class Solution {
public:
    int n;
    long long dp[51];
    vector<int> v[1000];
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        dp[0] = 1 , dp[1] = 2;
        for( int i = 2 ; i <= 50 ; i++ )
            dp[i] = dp[i-1] + dp[i-2];
        for(int x : nums)
            v[x%k].push_back(x/k);
        long long ans = 1;
        for( int kk = 0 ; kk < k ; kk++ ) {
            int n = v[kk].size();
            sort(v[kk].begin(),v[kk].end());
            for( int i = 0 , j = 0 ; i < n ; i = j ) {
                while(j < n and j-i == v[kk][j]-v[kk][i])
                    j++;
                ans *= dp[j-i];
            }
        }
        return ans;
    }
};
