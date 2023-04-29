const int maxv = 1000001;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int lastPrime = 0 , minDiff = INT_MAX;
        vector<int> ans(2,-1);
        vector<bool> prime(maxv,true);
        prime[0] = prime[1] = false;
        for( int i = 2 ; i < maxv ; i++ )
            if(prime[i]) {
                if(left <= i and i <= right) {
                    if(lastPrime) {
                        int diff = i-lastPrime;
                        if(diff < minDiff) {
                            minDiff = diff;
                            ans[0] = lastPrime;
                            ans[1] = i;
                        }
                    }
                    lastPrime = i;
                }
                if(i <= maxv/i)
                    for( int j = i*i ; j < maxv ; j += i )
                        prime[j] = false;
            }
        return ans;
    }
};
