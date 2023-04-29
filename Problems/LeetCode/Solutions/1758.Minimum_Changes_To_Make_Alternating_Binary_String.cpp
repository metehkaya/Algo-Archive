class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            cnt += (i%2) == (s[i]-'0');
        return min(cnt,n-cnt);
    }
};