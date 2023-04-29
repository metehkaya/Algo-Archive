class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        for(char c : t)
            cnt[c-'a']--;
        for(int x : cnt)
            ans += abs(x);
        return ans;
    }
};
