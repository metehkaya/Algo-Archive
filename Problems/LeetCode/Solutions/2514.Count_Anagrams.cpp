typedef long long LL;

const int mod = (int) 1e9+7;

class Solution {
public:
    LL calcPow(LL x , int y) {
        if(y == 0)
            return 1;
        LL res = calcPow(x,y/2);
        res = (res*res) % mod;
        if(y & 1)
            res = (res*x) % mod;
        return res;
    }
    int countAnagrams(string s) {
        s.push_back(' ');
        int n = s.length();
        vector<LL> fact(n+1,1);
        vector<LL> invFact(n+1,1);
        for( int i = 1 ; i <= n ; i++ ) {
            fact[i] = (fact[i-1] * i) % mod;
            invFact[i] = calcPow(fact[i],mod-2);
        }
        LL ans = 1;
        vector<int> v(26,0);
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                LL mult = fact[sum];
                for( int k = 0 ; k < 26 ; k++ ) {
                    mult = (mult * invFact[v[k]]) % mod;
                    v[k] = 0;
                }
                ans = (ans * mult) % mod;
                sum = 0;
                
            }
            else {
                sum++;
                v[s[i]-'a']++;
            }
        }
        return (int) ans;
    }
};
