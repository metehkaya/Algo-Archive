class Solution {
public:
    int countAsterisks(string s) {
        int n = s.length() , ans = 0;
        bool add = true;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '*')
                ans += add;
            else if(s[i] == '|')
                add = !add;
        return ans;
    }
};
