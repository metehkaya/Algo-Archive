#define pb push_back
typedef long long LL;

class Solution {
public:
    int 
    long long countPairs(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> v;
        vector<int> cnt(k+1,0);
        for( int i = 1 ; i <= k ; i++ )
            if(k%i == 0)
                v.push_back(i);
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int g = __gcd(ar[i],k);
            for( int x : v )
                if((LL)x*g % k == 0)
                    ans += cnt[x];
            cnt[g]++;
        }
        return ans;
    }
};
