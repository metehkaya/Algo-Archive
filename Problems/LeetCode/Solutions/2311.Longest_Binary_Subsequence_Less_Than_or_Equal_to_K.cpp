class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length() , ans = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int b = n-1-i;
            if(s[i] == '0')
                ans++;
            else if(b < 30 && (1<<b) <= k) {
                ans++;
                k -= (1<<b);
            }
        }
        return ans;
    }
};
