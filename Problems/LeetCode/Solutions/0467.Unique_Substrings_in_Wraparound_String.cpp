class Solution {
public:
    int mx[26];
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            j = i+1;
            while(j < n && (s[j] == s[j-1]+1 || (s[j] == 'a' && s[j-1] == 'z')))
                j++;
            int len = j-i;
            for( int k = 0 ; k < len ; k++ ) {
                int c = s[i+k] - 'a';
                mx[c] = max(mx[c],len-k);
            }
        }
        int ans = 0;
        for( int i = 0 ; i < 26 ; i++ )
            ans += mx[i];
        return ans;
    }
};