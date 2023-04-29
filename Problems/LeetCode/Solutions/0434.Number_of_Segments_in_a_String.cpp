class Solution {
public:
    int countSegments(string s) {
        s.push_back(' ');
        bool add = false;
        int n = s.length() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                ans += add;
                add = false;
            }
            else
                add = true;
        }
        return ans;
    }
};