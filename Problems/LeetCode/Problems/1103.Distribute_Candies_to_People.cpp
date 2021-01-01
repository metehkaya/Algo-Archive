class Solution {
public:
    vector<int> distributeCandies(int m, int n) {
        int i = 0 , give = 0;
        vector<int> ans(n,0);
        while(m) {
            give = min(give+1,m);
            m -= give;
            ans[i] += give;
            i = (i+1)%n;
        }
        return ans;
    }
};