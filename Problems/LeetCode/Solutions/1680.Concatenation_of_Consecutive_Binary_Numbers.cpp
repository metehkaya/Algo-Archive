class Solution {
public:
    const int MOD = (int) 1e9+7;
    int concatenatedBinary(int n) {
        int ans = 0;
        for( int num = 1 ; num <= n ; num++ ) {
            bool add = false;
            for( int k = 16 ; k >= 0 ; k-- ) {
                int x = (num & (1<<k)) ? 1 : 0;
                if(x)
                    add = true;
                if(add)
                    ans = (2*ans+x) % MOD;
            }
        }
        return ans;
    }
};