class Solution {
public:
    double ans;
    void f(int x1 , int y1 , int x2 , int y2 , int x3 , int y3) {
        double res = 0;
        res += x1*y2 + x2*y3 + x3*y1;
        res -= x2*y1 + x3*y2 + x1*y3;
        if(res < 0)
            res = -res;
        ans = max(ans,res/2.0);
    }
    double largestTriangleArea(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    f(ar[i][0],ar[i][1],ar[j][0],ar[j][1],ar[k][0],ar[k][1]);
        return ans;
    }
};