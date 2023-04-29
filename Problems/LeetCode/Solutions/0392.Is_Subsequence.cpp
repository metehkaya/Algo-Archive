class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        for( int i = 0 , index = 0 ; i < n ; i++ , index++ ) {
            while(index < m && t[index] != s[i])
                index++;
            if(index == m)
                return false;
        }
        return true;
    }
};