class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        int ans = 0;
        for(int x : cnt) {
            if(x <= 2)
                ans += x;
            else
                ans += 2 - x%2;
        }
        return ans;
    }
};