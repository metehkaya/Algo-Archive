class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        for( int p = 2 ; p <= 1000 ; p++ ) {
            bool ok = true;
            for( int i = 2 ; i*i <= p ; i++ )
                if(p%i == 0) {
                    ok = false;
                    break;
                }
            if(ok)
                primes.push_back(p);
        }
        reverse(primes.begin(),primes.end());
        int n = nums.size() , m = primes.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(i > 0 and nums[i] <= nums[i-1])
                return false;
            for( int j = 0 ; j < m ; j++ )
                if(primes[j] < nums[i] and (i == 0 or nums[i-1] < nums[i]-primes[j])) {
                    nums[i] -= primes[j];
                    break;
                }
        }
        return true;
    }
};
