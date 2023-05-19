typedef long long LL;

class Solution {
public:
    const int mod = 1e9+7;
    int sumOfPower(vector<int>& v) {
        int n = v.size() , ans = 0 , sum = 0;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ ) {
            if(i)
                sum = (2*sum%mod + v[i-1]) % mod;
            LL add = (sum+v[i]) % mod;
            add = add * v[i] % mod * v[i] % mod;
            ans = (ans + add) % mod;
        }
        return ans;
    }
};
