class Solution {
public:
    int maxScore(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int x : nums) {
            sum += x;
            if(sum > 0)
                ans++;
        }
        return ans;
    }
};
