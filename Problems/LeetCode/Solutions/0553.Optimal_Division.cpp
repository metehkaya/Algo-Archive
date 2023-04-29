class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return to_string(nums[0]);
        if(n == 2)
            return to_string(nums[0])+"/"+to_string(nums[1]);
        string ans = to_string(nums[0])+"/(";
        for( int i = 1 ; i < n ; i++ ) {
            ans += to_string(nums[i]);
            if(i+1 < n)
                ans.push_back('/');
        }
        ans.push_back(')');
        return ans;
    }
};
