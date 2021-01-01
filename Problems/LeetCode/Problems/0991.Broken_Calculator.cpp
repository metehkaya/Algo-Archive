class Solution {
public:
    int brokenCalc(int x, int y) {
        int ans = 0;
        while(y > x) {
            ans++;
            if(y % 2)
                y++;
            else
                y /= 2;
        }
        ans += x-y;
        return ans;
    }
};