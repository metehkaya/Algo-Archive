class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int x : nums)
            ans += (x < k);
        return ans;
    }
};