class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int ans = -1;
        for( int x : nums )
            if(x > 0 && s.count(-x))
                ans = max(ans,x);
        return ans;
    }
};
