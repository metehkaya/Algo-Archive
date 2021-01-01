class Solution {
public:
    int minFlips(string s) {
        int n = s.length() , cnt = 1;
        for( int i = 1 ; i < n ; i++ )
            cnt += s[i] != s[i-1];
        if(s[0] == '0')
            cnt--;
        return cnt;
    }
};