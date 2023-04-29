#define mod 1000000007
typedef long long LL;

class Solution {
public:
    int maximumProduct(vector<int>& ar, int k) {
        ar.push_back(INT_MAX);
        sort(ar.begin(),ar.end());
        int n = ar.size();
        for( int i = 1 ; i < n ; i++ ) {
            LL must = (LL)i*(ar[i]-ar[i-1]);
            if(must <= k)
                k -= must;
            else {
                int add = k/i;
                for( int j = 0 ; j < i ; j++ )
                    ar[j] = ar[i-1]+add;
                k %= i;
                for( int j = 0 ; j < k ; j++ )
                    ar[j]++;
                break;
            }
        }
        LL ans = 1;
        for( int i = 0 ; i < n-1 ; i++ )
            ans = ans*ar[i] % mod;
        return (int)ans;
    }
};
