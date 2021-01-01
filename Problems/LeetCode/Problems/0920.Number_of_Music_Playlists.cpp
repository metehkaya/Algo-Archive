typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int numMusicPlaylists(int N, int L, int K) {
        vii comb(N+1,vi(N+1,0));
        for( int i = 0 ; i <= N ; i++ )
            comb[i][0] = 1;
        for( int i = 1 ; i <= N ; i++ )
            for( int j = 1 ; j <= i ; j++ )
                comb[i][j] = ( comb[i-1][j] + comb[i-1][j-1] ) % MOD;
        int ans = 0;
        for( int n = N ; n > K ; n-- ) {
            LL add = 1;
            for( int i = 0 ; i < L ; i++ )
                if(i <= K)
                    add = (add * (n-i)) % MOD;
                else
                    add = (add * (n-K)) % MOD;
            add = (add * comb[N][n]) % MOD;
            if(n % 2 != N % 2)
                add = MOD - add;
            ans = (ans + add) % MOD;
        }
        return ans;
    }
};