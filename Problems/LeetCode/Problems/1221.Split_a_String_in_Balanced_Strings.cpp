class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();
        int ans = 0 , cnt = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == 'L')
                cnt++;
            else
                cnt--;
            if(cnt == 0)
                ans++;
        }
        return ans;
    }
};