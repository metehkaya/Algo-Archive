class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for( int i = 0 ; i <= 30 ; i++ )
            ans += (x&(1<<i)) != (y&(1<<i));
        return ans;
    }
};