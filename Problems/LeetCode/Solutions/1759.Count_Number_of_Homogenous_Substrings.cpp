class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int countHomogenous(string s) {
        long long ans = 0;
        int n = s.length();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            long long k = j-i;
            ans += k*(k+1)/2;
        }
        return ans % MOD;
    }
};