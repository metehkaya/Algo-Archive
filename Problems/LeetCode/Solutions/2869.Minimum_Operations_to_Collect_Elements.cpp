class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        set<int> s;
        int ans = 0;
        for(int x : nums) {
            ans++;
            if(x <= k) {
                s.insert(x);
                if(s.size() == k)
                    break;
            }
        }
        return ans;
    }
};
