class Solution {
public:
    long long f(vector<int>& nums) {
        long long res = LLONG_MIN , sum = 0;
        for(int x : nums) {
            sum += x;
            res = max(res,sum);
        }
        return res;
    }
    long long maximumSumScore(vector<int>& nums) {
        long long res1 = f(nums);
        reverse(nums.begin(),nums.end());
        long long res2 = f(nums);
        return max(res1,res2);
    }
};
