class Solution {
public:
    int f(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size() , res = 1;
        for( int l = 0 , r = 0 ; l < n ; l = r ) {
            while(r < n and v[r]-v[l] == r-l)
                r++;
            res = max(res,r-l+1);
        }
        return res;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int val_h = f(hBars) , val_v = f(vBars);
        int val = min(val_h,val_v);
        return val*val;
    }
};
