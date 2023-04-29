class Solution {
public:
    int minInsertions(string s) {
        int n = s.length() , cnt = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '(')
                cnt++;
            else {
                if(i+1 < n && s[i+1] == ')') {
                    if(cnt)
                        cnt--;
                    else
                        ans++;
                    i++;
                }
                else {
                    ans++;
                    if(cnt)
                        cnt--;
                    else
                        ans++;
                }
            }
        }
        return ans+2*cnt;
    }
};