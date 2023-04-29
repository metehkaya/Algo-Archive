typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    const int mod = (int)1e9+7;
    LL pw(int x , int y) {
        if(y == 0)
            return 1;
        LL res = pw(x,y/2);
        res = res * res % mod;
        if(y&1)
            res = res * x % mod;
        return res;
    }
    LL comb(int l , int r , int m , vector<LL>& fact) {
        LL res = fact[r-l];
        res = res * pw(fact[m-l],mod-2)%mod;
        res = res * pw(fact[r-m],mod-2)%mod;
        return res;
    }
    int numOfWays(vector<int>& ar) {
        int n = ar.size();
        set<pi> s;
        set<pi>::iterator it;
        s.insert(pi(1,n));
        vector<LL> fact(n+1,1);
        for( int i = 1 ; i <= n ; i++ )
            fact[i] = fact[i-1] * i % mod;
        LL ans = 1;
        for( int i = 0 ; i < n ; i++ ) {
            int val = ar[i];
            it = s.upper_bound(pi(ar[i],n));
            it--;
            int l = (*it).first;
            int r = (*it).second;
            s.erase(it);
            int len = r-l+1;
            ans = ans * comb(l,r,val,fact) % mod;
            if(l<val)
                s.insert(pi(l,val-1));
            if(val<r)
                s.insert(pi(val+1,r));
        }
        ans = (ans+mod-1)%mod;
        return (int) ans;
    }
};