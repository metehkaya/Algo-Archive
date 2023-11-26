class Solution {
public:
    long long maxGcdSum(vector<int>& vals, int k) {
        long long ans = 0;
        int n = vals.size();
        vector<vector<int>> gcds;
        vector<long long> sum({0});
        for( int i = 0 ; i < n ; i++ ) {
            vector<vector<int>> new_gcds;
            sum.push_back(sum[i]+vals[i]);
            for(auto& v : gcds) {
                int g = v[0] , idx = v[1];
                int new_g = __gcd(g,vals[i]);
                int sz = new_gcds.size();
                if(sz == 0 or new_gcds[sz-1][0] != new_g)
                    new_gcds.push_back({new_g,idx});
            }
            int sz = new_gcds.size();
            if(sz == 0 or new_gcds[sz-1][0] != vals[i])
                new_gcds.push_back({vals[i],i});
            gcds = new_gcds;
            for(auto& v : gcds) {
                int g = v[0] , idx = v[1];
                int len = i-idx+1;
                if(len >= k)
                    ans = max(ans,g*(sum[i+1]-sum[idx]));
            }
        }
        return ans;
    }
};

