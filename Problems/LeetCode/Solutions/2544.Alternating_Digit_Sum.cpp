class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        n = s.length();
        int ans = 0 , add = 1;
        for( int i = 0 ; i < n ; i++ ) {
            ans += add * (s[i]-'0');
            add = -add;
        }
        return ans;
    }
};
