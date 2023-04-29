class Solution {
public:
    int numWaterBottles(int n, int k) {
        int x = n , y = 0 , ans = 0;
        while(x) {
            ans += x;
            y += x;
            x = y/k;
            y %= k;
        }
        return ans;
    }
};