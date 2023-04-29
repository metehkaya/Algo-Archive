class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int ans = 1;
        while(s.count(ans))
            ans <<= 1;
        return ans;
    }
};
