class Solution {
public:
    int minTimeToType(string s) {
        int n = s.length();
        int ans = n;
        s = "a" + s;
        for( int i = 1 ; i <= n ; i++ ) {
            int diff = (int) s[i] - (int) s[i-1];
            diff = abs(diff);
            ans += min(diff,26-diff);
        }
        return ans;
    }
};