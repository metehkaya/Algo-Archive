typedef long long LL;

class Solution {
public:
    vector<LL> minOperations(vector<int>& nums, vector<int>& queries) {
        LL total = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<LL> sum;
        for( int i = 0 ; i < n ; i++ ) {
            total += nums[i];
            sum.push_back(total);
        }
        vector<LL> ans;
        for(int q : queries) {
            int idx = upper_bound(nums.begin(),nums.end(),q) - nums.begin();
            LL l = idx == 0 ? 0 : (LL)q*idx - sum[idx-1];
            LL r = 0;
            if(idx < n)
                r = (idx == 0 ? total : total - sum[idx-1]) - (LL)q*(n-idx);
            ans.push_back(l+r);
        }
        return ans;
    }
};
