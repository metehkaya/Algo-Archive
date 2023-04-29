class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        vector<long long> ans(1,0);
        stack<int> gteq,less;
        gteq.push(0);
        less.push(0);
        for( int i = 1 ; i < n ; i++ ) {
            long long res = LLONG_MAX;
            while(!gteq.empty() and nums[i] >= nums[gteq.top()]) {
                res = min(res,ans[gteq.top()]+costs[i]);
                gteq.pop();
            }
            gteq.push(i);
            while(!less.empty() and nums[i] < nums[less.top()]) {
                res = min(res,ans[less.top()]+costs[i]);
                less.pop();
            }
            less.push(i);
            ans.push_back(res);
        }
        return ans.back();
    }
};
