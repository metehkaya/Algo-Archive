typedef long long LL;

class Solution {
public:
    const int MOD = (int) 1e9+7;
    int numSub(string s) {
        LL ans = 0;
        int n = s.length();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[j] == '0')
                j++;
            i = j;
            while(j < n && s[j] == '1')
                j++;
            ans += (LL) (j-i) * (j-i+1) / 2;
            ans %= (LL) MOD;
        }
        return (int) ans;
    }
};