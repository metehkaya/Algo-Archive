class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        bool mark[256] = {0};
        for( int i = 0 , j = 0 ; i < n && j < n ; i++ ) {
            while( j < n && !mark[s[j]] )
                mark[s[j++]] = true;
            ans = max(ans, j-i);
            mark[s[i]] = false;
        }
        return ans;
    }
};