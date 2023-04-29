class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for( int i = 1 ; i < n-1 ; i++ )
            if(s[i-1] != s[i] && s[i] != s[i+1] && s[i-1] != s[i+1])
                ans++;
        return ans;
    }
};