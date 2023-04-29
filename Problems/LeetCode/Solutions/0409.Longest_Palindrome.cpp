class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length() , ans = 0;
        vector<bool> odd(52,0);
        for( int i = 0 ; i < n ; i++ ) {
            int c;
            if(s[i] >= 'a' && s[i] <= 'z')
                c = s[i]-'a';
            else
                c = s[i]-'A'+26;
            odd[c] = !odd[c];
            if(!odd[c])
                ans += 2;
        }
        for( int i = 0 ; i < 52 ; i++ )
            if(odd[i]) {
                ans++;
                break;
            }
        return ans;
    }
};