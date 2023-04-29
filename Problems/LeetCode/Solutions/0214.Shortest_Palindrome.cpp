class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        string mixed = s+"#"+t;
        int len = mixed.length();
        vector<int> lps(len,0);
        int i = 1 , j = 0;
        while(i < len) {
            if(mixed[i] == mixed[j])
                lps[i++] = ++j;
            else {
                if(j != 0)
                    j = lps[j-1];
                else
                    lps[i++] = 0;
            }
        }
        return t.substr(0,n-lps[len-1])+s;
    }
};
