class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), total = 0;
        vector<int> dp;
        for( int i = 0 ; i < n-1 ; i++ ) {
            total += ((nums[i] % 2) != (nums[i+1] % 2));
            dp.push_back(total);
        }
        vector<bool> ans;
        for(auto q : queries) {
            int l = q[0] , r = q[1];
            if(l == r)
                ans.push_back(true);
            else {
                int req = r-l;
                int cnt = dp[r-1];
                if(l > 0)
                    cnt -= dp[l-1];
                ans.push_back(cnt == req);
            }
        }
        return ans;
    }
};