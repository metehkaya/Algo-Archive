class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length() , ans = 0 , cnt = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '(')
                cnt++;
            else if(cnt)
                cnt--;
            else
                ans++;
        }
        ans += cnt;
        return ans;
    }
};