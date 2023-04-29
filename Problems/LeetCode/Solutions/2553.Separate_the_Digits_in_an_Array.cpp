class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int x : nums) {
            vector<int> v;
            while(x) {
                v.push_back(x%10);
                x /= 10;
            }
            reverse(v.begin(),v.end());
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};
