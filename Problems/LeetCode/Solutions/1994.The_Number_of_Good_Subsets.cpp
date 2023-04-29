typedef long long LL;

class Solution {
public:
    int n;
    int cnt[31];
    bool ok[(1<<18)];
    int freq[(1<<18)][6];
    int primes[6] = {2,3,5,7,11,13};
    int nums[18] = {2,3,5,6,7,10,11,13,14,15,17,19,21,22,23,26,29,30};
    const int mod = (int) 1e9+7;
    int numberOfGoodSubsets(vector<int>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        LL ans = 0;
        ok[0] = true;
        for( int bmask = 1 ; bmask < (1<<18) ; bmask++ ) {
            LL mult = 1;
            bool calc = true;
            ok[bmask] = true;
            for( int i = 0 ; i < 18 ; i++ )
                if(bmask & (1<<i)) {
                    mult = (mult * cnt[nums[i]]) % mod;
                    if(calc) {
                        calc = false;
                        int temp = nums[i];
                        int bmask2 = bmask - (1<<i);
                        if(!ok[bmask2]) {
                            ok[bmask] = false;
                            break;
                        }
                        for( int j = 0 ; j < 6 ; j++ ) {
                            freq[bmask][j] = freq[bmask2][j];
                            while(temp % primes[j] == 0) {
                                freq[bmask][j]++;
                                temp /= primes[j];
                            }
                        }
                    }
                }
            if(ok[bmask]) {
                for( int i = 0 ; i < 6 ; i++ )
                    if(freq[bmask][i] > 1)
                        ok[bmask] = false;
                if(ok[bmask])
                    ans = (ans + mult) % mod;
            }
        }
        for( int i = 0 ; i < cnt[1] ; i++ )
            ans = (ans * 2) % mod;
        return (int) ans;
    }
};