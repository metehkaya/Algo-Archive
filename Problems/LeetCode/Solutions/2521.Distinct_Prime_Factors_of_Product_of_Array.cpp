const int maxv = 1001;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes;
        vector<bool> prime(maxv,true);
        prime[0] = prime[1] = false;
        for( int i = 2 ; i < maxv ; i++ )
            if(prime[i]) {
                primes.push_back(i);
                for( int j = i*i ; j < maxv ; j += i )
                    prime[j] = false;
            }
        set<int> ans;
        for(int num : nums) {
            for(int p : primes)
                if(num % p == 0)
                    ans.insert(p);
        }
        return ans.size();
    }
};
