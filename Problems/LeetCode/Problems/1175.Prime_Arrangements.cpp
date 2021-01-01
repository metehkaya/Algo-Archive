typedef long long LL;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int numPrimeArrangements(int n) {
        vector<bool> isPrime(n+1,true);
        isPrime[1] = false;
        int p = 0;
        for( int i = 2 ; i <= n ; i++ )
            if(isPrime[i]) {
                for( int j = 2*i ; j <= n ; j += i )
                    isPrime[j] = false;
                p++;
            }
        vector<int> fact(n+1,1);
        for( int i = 2 ; i <= n ; i++ )
            fact[i] = ( (LL) fact[i-1] * i ) % MOD;
        return (LL) fact[p] * fact[n-p] % MOD;
    }
};