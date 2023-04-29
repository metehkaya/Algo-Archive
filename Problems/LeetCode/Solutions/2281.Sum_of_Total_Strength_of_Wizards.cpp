typedef long long LL;
const LL mod = 1e9+7;

class Solution {
public:
    LL get_score_b(int i , int j , vector<LL>& sum_b , vector<LL>& total_b) {
        if(i > j)
            return 0;
        LL x = (total_b[i]-total_b[j+1]+mod) % mod;
        LL y = (j-i+1) * sum_b[j+1] % mod;
        return (x-y+mod) % mod;
    }
    LL get_score_f(int i , int j , vector<LL>& sum_f , vector<LL>& total_f) {
        if(i > j)
            return 0;
        LL x = (total_f[j]-total_f[i-1]+mod) % mod;
        LL y = (j-i+1) * sum_f[i-1] % mod;
        return (x-y+mod) % mod;
    }
    int totalStrength(vector<int>& str) {
        int n = str.size();
        vector<LL> sum_f(n), total_f(n);
        vector<LL> sum_b(n), total_b(n);
        sum_f[0] = total_f[0] = str[0];
        for( int i = 1 ; i < n ; i++ ) {
            sum_f[i] = (sum_f[i-1]+str[i])%mod;
            total_f[i] = (total_f[i-1]+sum_f[i])%mod;
        }
        sum_b[n-1] = total_b[n-1] = str[n-1];
        for( int i = n-2 ; i >= 0 ; i-- ) {
            sum_b[i] = (sum_b[i+1]+str[i])%mod;
            total_b[i] = (total_b[i+1]+sum_b[i])%mod;
        }
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({str[i],i});
        sort(v.begin(),v.end());
        set<int> indices({-1,n});
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int val = v[i][0] , idx = v[i][1];
            auto it = indices.upper_bound(idx);
            int r = (*it)-1;
            it = indices.lower_bound(idx);
            it--;
            int l = (*it)+1;
            LL score_f = get_score_f(idx+1,r,sum_f,total_f) * (idx-l+1) % mod;
            LL score_b = get_score_b(l,idx-1,sum_b,total_b) * (r-idx+1) % mod;
            LL score_val = (LL) val * (idx-l+1) * (r-idx+1) % mod;
            LL score = (score_f+score_b+score_val) % mod;
            ans = (ans+(score*val)) % mod;
            indices.insert(idx);
        }
        return ans;
    }
};
