class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if(n == 1)
            return "";
        string ans = "";
        for( int i = 0 ; i*2 <= n ; i++ )
            if(s[i] != 'a' && 2*i+1 != n) {
                ans = s.substr(0,i) + "a" + s.substr(i+1);
                break;
            }
        if(ans == "")
            ans = s.substr(0,n-1) + "b";
        return ans;
    }
};