class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        s.erase(0);
        return (int) s.size();
    }
};
