class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n);
        lps[0] = 0;
        int i = 1 , len = 0;
        while(i < n) {
            if( s[i] == s[len] )
                lps[i++] = ++len;
            else {
                if(len > 0)
                    len = lps[len-1];
                else
                    lps[i++] = 0;
            }
        }
        int p = lps[n-1];
        return s.substr(0,p);
    }
};