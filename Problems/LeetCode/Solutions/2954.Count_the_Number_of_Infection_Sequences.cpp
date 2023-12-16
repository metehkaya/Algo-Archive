typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    LL calc_pow(LL x , int y) {
        if(y == 0)
            return 1;
        LL res = calc_pow(x,y/2);
        res = res*res % mod;
        if(y & 1)
            res = res*x % mod;
        return res;
    }
    int numberOfSequence(int n, vector<int>& sick) {
        vector<LL> fact(n+1,1);
        for( int i = 1 ; i <= n ; i++ )
            fact[i] = fact[i-1]*i % mod;
        int m = sick.size();
        vector<pair<int,bool>> v;
        if(sick[0] > 0)
            v.push_back(make_pair(sick[0],false));
        if(sick[m-1] < n-1)
            v.push_back(make_pair(n-1-sick[m-1],false));
        for( int i = 1 ; i < m ; i++ )
            if(sick[i] - sick[i-1] > 1)
                v.push_back(make_pair(sick[i]-sick[i-1]-1,true));
        int rem = n-m;
        LL ans = 1;
        for(auto pr : v) {
            int x = pr.first;
            if(pr.second)
                ans = ans * calc_pow(2,x-1) % mod;
            LL q = fact[x]*fact[rem-x] % mod;
            LL mult = fact[rem] * calc_pow(q,mod-2) % mod;
            ans = ans * mult % mod;
            rem -= x;
        }
        return ans;
    }
};
