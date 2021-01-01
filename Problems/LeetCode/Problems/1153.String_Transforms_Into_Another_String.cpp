class Solution {
public:
    bool canConvert(string s, string t) {
        if(s == t)
            return true;
        int n = s.length();
        char dp[26] = {0};
        for( int i = 0 ; i < n ; i++ ) {
            int v = s[i]-'a';
            if(dp[v] && dp[v] != t[i])
                return false;
            dp[v] = t[i];
        }
        return set(t.begin(), t.end()).size() < 26;
    }
};