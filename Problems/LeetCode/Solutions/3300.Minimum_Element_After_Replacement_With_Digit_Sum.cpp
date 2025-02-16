class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int x : nums) {
            string s = to_string(x);
            int sum = 0;
            for(char c : s)
                sum += c-'0';
            ans = min(ans,sum);
        }
        return ans;
    }
};