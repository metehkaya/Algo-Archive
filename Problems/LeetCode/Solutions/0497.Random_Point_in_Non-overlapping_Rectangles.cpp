class Solution {
public:
    int n,lim;
    vector<int> v;
    vector<vector<int>> ar;
    Solution(vector<vector<int>>& rects) {
        ar = rects;
        n = ar.size();
        lim = 0;
        for( int i = 0 ; i < n ; i++ ) {
            v.push_back((ar[i][2]-ar[i][0]+1)*(ar[i][3]-ar[i][1]+1));
            lim += v[i];
        }
    }
    vector<int> pick() {
        int i = 0;
        int rem = rand() % lim;
        while(rem >= v[i])
            rem -= v[i++];
        vector<int> ans(2);
        int diff = ar[i][3]-ar[i][1]+1;
        ans[0] = ar[i][0] + rem/diff;
        ans[1] = ar[i][1] + rem%diff;
        return ans;
    }
};