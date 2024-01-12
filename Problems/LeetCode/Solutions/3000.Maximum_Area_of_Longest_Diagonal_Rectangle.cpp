class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxdiag = 0 , ans = 0;
        for(auto v : dimensions) {
            int diag = v[0]*v[0]+v[1]*v[1];
            if(diag > maxdiag) {
                maxdiag = diag;
                ans = v[0]*v[1];
            }
            else if(diag == maxdiag)
                ans = max(ans,v[0]*v[1]);
        }
        return ans;
    }
};
