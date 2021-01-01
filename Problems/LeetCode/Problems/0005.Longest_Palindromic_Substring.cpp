class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1)
            return s;
        int ansLen=0,ansL;
        for( int i = 0 ; i < n ; i++ ) {
            int l=i,r=i;
            while(l-1 >= 0 && r+1 < n && s[l-1] == s[r+1])
                l--,r++;
            if(r-l+1 > ansLen)
                ansLen=r-l+1,ansL=l;
            if(i+1 < n && s[i] == s[i+1]) {
                l=i,r=i+1;
                while(l-1 >= 0 && r+1 < n && s[l-1] == s[r+1])
                    l--,r++;
                if(r-l+1 > ansLen)
                    ansLen=r-l+1,ansL=l;
            }
        }
        return s.substr(ansL, ansLen);
    }
};