typedef long long LL;

class Solution {
public:
    const int maxs = (int) 1e5+1;
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
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primes;
        vector<bool> prime_status(maxs,true);
        for( int p = 2 ; p < maxs ; p++ )
            if(prime_status[p]) {
                primes.push_back(p);
                if(p <= maxs/p)
                    for( int val = p*p ; val < maxs ; val += p )
                        prime_status[val] = false;
            }
        int n = nums.size() , n_primes = primes.size();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ ) {
            int num = nums[i] , cnt = 0;
            int sq = (int) sqrt(num);
            for( int idx = 0 ; idx < n_primes and primes[idx]*primes[idx] <= nums[i] ; idx++ )
                if(num % primes[idx] == 0) {
                    cnt++;
                    while(num % primes[idx] == 0)
                        num /= primes[idx];
                }
            if(num > 1)
                cnt++;
            v.push_back({cnt,-i,nums[i]});
        }
        sort(v.begin(),v.end());
        set<int> s({-1,n});
        map<int,LL> scores;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int idx = -v[i][1] , val = v[i][2];
            auto it = s.upper_bound(idx);
            int r = (*it)-idx;
            it--;
            int l = idx-(*it);
            int freq = (int) min((LL)k,(LL)l*r);
            scores[val] += freq;
            scores[val] = min(scores[val],(LL)k);
            s.insert(idx);
        }
        LL ans = 1;
        for( auto it = scores.rbegin() ; it != scores.rend() ; it++ ) {
            int val = it->first , freq = it->second;
            int mult = min(k,freq);
            ans = ans * calc_pow(val,mult) % mod;
            if(k < freq)
                break;
            k -= freq;
        }
        return ans;
    }
};