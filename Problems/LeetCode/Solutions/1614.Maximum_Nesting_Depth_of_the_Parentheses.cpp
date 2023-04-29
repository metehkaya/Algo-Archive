class Solution {
public:
    int maxDepth(string s) {
        int n = s.length() , cnt = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == '(')
                cnt++;
            else if(c == ')')
                cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};