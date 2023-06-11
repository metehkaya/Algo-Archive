class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length() , ans = 1;
        for( int i = 0 ; i < n ; i++ ) {
            int j = i+1 , cnt = 0;
            while(j < n) {
                if(s[j] == s[j-1])
                    cnt++;
                if(cnt > 1)
                    break;
                j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};
