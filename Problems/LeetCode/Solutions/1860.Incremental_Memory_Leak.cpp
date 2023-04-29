class Solution {
public:
    vector<int> memLeak(int x, int y) {
        vector<int> ans(3);
        for( int i = 1 ; ; i++ ) {
            int mx = max(x,y);
            if(mx < i) {
                ans[0] = i;
                ans[1] = x;
                ans[2] = y;
                break;
            }
            if(x >= y)
                x -= i;
            else
                y -= i;
        }
        return ans;
    }
};