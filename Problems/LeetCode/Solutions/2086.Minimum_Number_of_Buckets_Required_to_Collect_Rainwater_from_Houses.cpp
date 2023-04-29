class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == 'H') {
                if(i-1 >= 0 && s[i-1] == '.')
                    continue;
                if(i+1 < n && s[i+1] == '.')
                    continue;
                return -1;
            }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == 'H') {
                if(i-1 >= 0 && s[i-1] == 'x')
                    continue;
                if(i+1 < n && s[i+1] == '.') {
                    ans++;
                    s[i+1] = 'x';
                }
                else if(i-1 >= 0 && s[i-1] == '.') {
                    ans++;
                    s[i-1] = 'x';
                }
            }
        return ans;
    }
};
