class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int x : nums)
            sum += x;
        return sum % 2 == 0 ? n-1 : 0;
    }
};