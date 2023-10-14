class Solution {
public:
    long long maximumSum(vector<int>& v) {
        int n = v.size();
        long long ans = 0;
        map<vector<int>,long long> mp;
        for( int i = 1 ; i <= n ; i++ ) {
            int x = i;
            vector<int> primes;
            for( int j = 2 ; j <= 100 ; j++ ) {
                bool mark = false;
                while(x % j == 0) {
                    mark = !mark;
                    x /= j;
                }
                if(mark)
                    primes.push_back(j);
            }
            if(x > 1)
                primes.push_back(x);
            mp[primes] += v[i-1];
            ans = max(ans,mp[primes]);
        }
        return ans;
    }
};
