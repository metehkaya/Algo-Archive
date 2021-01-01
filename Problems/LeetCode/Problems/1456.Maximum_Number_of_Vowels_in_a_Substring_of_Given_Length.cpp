class Solution {
public:
    bool check(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int cnt = 0;
        int n = s.length();
        for( int i = 0 ; i < k ; i++ )
            cnt += check(s[i]);
        int ans = cnt;
        for( int i = k ; i < n ; i++ ) {
            cnt += check(s[i]);
            cnt -= check(s[i-k]);
            ans = max( ans , cnt );
        }
        return ans;
    }
};