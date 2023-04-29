class Solution {
public:
    const int mod = (int) 1e9+7;
    static const int maxk = 201;
    static const int maxn = 50000;
    int sum[maxk][maxn];
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for( int k = 1 ; k < maxk ; k++ )
            for( int i = n-1 ; i >= 0 ; i-- )
                sum[k][i] = (nums[i] + ((i+k >= n) ? 0 : sum[k][i+k])) % mod;
        vector<int> ans;
        for(auto& q : queries) {
            int idx = q[0] , k = q[1];
            if(k < maxk)
                ans.push_back(sum[k][idx]);
            else {
                int res = 0;
                for( int i = idx ; i < n ; i += k )
                    res = (res + nums[i]) % mod;
                ans.push_back(res);
            }
        }
        return ans;
    }
};
