class Solution {
public:
    static const int maxn = 5000001;
    bool divv[maxn];
    int countPrimes(int n) {
        n--;
        int ans = 0;
        for( int i = 2 ; i <= n ; i++ )
            if(!divv[i]) {
                ans++;
                if(i <= n/i)
                    for( int j = i*i ; j <= n ; j += i )
                        divv[j] = true;
            }
        return ans;
    }
};