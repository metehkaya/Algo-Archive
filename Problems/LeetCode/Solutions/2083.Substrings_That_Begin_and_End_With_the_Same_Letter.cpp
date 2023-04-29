class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ans = 0;
        vector<int> cnt(26,0);
        for(char c : s)
            ans += ++cnt[c-'a'];
        return ans;
    }
};
