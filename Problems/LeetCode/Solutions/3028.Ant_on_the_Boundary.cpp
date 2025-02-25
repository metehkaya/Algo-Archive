class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0 , curr = 0;
        for(int x : nums) {
            curr += x;
            ans += (curr == 0);
        }
        return ans;
    }
};