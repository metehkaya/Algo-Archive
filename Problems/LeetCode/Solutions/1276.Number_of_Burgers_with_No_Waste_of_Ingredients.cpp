class Solution {
public:
    vector<int> numOfBurgers(int x, int y) {
        vector<int> ans(2);
        ans[0] = (x-2*y) / 2;
        ans[1] = y-ans[0];
        if(4*ans[0]+2*ans[1] != x || ans[0]+ans[1] != y || min(ans[0],ans[1]) < 0)
            ans.clear();
        return ans;
    }
};