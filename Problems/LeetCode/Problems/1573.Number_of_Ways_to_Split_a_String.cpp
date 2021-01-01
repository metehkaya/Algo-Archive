#define pb push_back
#define mod 1000000007
typedef long long LL;

class Solution {
public:
    int numWays(string s) {
        int n = s.length();
        vector<int> ones;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '1')
                ones.pb(i);
        int k = ones.size();
        if(k%3)
            return 0;
        if(k == 0) {
            if(n < 3)
                return 0;
            else
                return (LL) (n-1) * (n-2) / 2 % mod;
        }
        int i = ones[k/3]-ones[k/3-1];
        int j = ones[2*k/3]-ones[2*k/3-1];
        return (LL)i*j%mod;
    }
};