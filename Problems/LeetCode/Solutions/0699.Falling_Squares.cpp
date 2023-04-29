class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> h,ans;
        for( int i = 0 ; i < n ; i++ ) {
            int x = v[i][0] , y = v[i][0]+v[i][1]-1;
            int mx = 0;
            for( int j = 0 ; j < i ; j++ ) {
                int xx = v[j][0] , yy = v[j][0]+v[j][1]-1;
                xx = max(x,xx);
                yy = min(y,yy);
                if(xx <= yy)
                    mx = max(mx,h[j]);
            }
            mx += v[i][1];
            h.push_back(mx);
            int prev = (ans.empty() ? 0 : ans[i-1]);
            ans.push_back(max(mx,prev));
        }
        return ans;
    }
};
