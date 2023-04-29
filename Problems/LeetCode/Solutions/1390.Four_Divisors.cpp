class Solution {
public:
    const int MAXVAL = 100001;
    int sumFourDivisors(vector<int>& ar) {
        int ans = 0;
        int n = ar.size();
        vector<int> prime(MAXVAL,-1);
        for( int i = 2 ; i*i < MAXVAL ; i++ )
            if( prime[i] == -1 ) {
                for( int j = i*i ; j < MAXVAL ; j += i )
                    prime[j] = i;
            }
        for( int i = 0 ; i < n ; i++ )
            if( prime[ar[i]] != -1 ) {
                int p = prime[ar[i]];
                if(p*p*p == ar[i])
                    ans += 1+p+p*p+p*p*p;
                else if(p*p != ar[i] && prime[ar[i]/p] == -1)
                    ans += 1+p+ar[i]/p+ar[i];
            }
        return ans;
    }
};