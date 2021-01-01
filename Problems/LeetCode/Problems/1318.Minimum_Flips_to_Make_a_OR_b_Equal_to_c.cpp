class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for( int i = 0 ; i < 30 ; i++ ) {
            int x = (a & (1 << i)) >> i;
            int y = (b & (1 << i)) >> i;
            int z = (c & (1 << i)) >> i;
            if((x | y) != z) {
                if(z == 1)
                    ans++;
                else
                    ans += x+y;
            }
        }
        return ans;
    }
};