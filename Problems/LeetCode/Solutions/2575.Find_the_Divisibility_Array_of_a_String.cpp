class Solution {
public:
    vector<int> divisibilityArray(string s, int m) {
        int n = s.length();
        long long val = 0;
        vector<int> ans;
        for(char c : s) {
            val = (10*val+c-'0') % m;
            ans.push_back(!val);
        }
        return ans;
    }
};
