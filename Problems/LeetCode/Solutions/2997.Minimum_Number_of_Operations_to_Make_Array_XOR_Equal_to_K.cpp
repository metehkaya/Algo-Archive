class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int val = k , ans = 0;
        for(int num : nums)
            val = (val ^ num);
        while(val) {
            ans++;
            val -= (val & (-val));
        }
        return ans;
    }
};
