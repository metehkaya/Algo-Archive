class Solution {
public:
    bool isReachable(int x, int y) {
        int g = __gcd(x,y);
        return g > 0 and (g & (g-1)) == 0;
    }
};
