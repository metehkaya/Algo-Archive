class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int ans = 0;
        int last = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            int cnt = j-i;
            ans += min(last,cnt);
            last = cnt;
        }
        return ans;
    }
};