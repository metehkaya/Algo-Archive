class Solution {
public:
    int ccw(vector<int>& a , vector<int>& b , vector<int>& c) {
        int dx1 = b[0]-a[0];
        int dy1 = b[1]-a[1];
        int dx2 = c[0]-a[0];
        int dy2 = c[1]-a[1];
        return dx1*dy2 - dx2*dy1;
    }
    bool isConvex(vector<vector<int>>& v) {
        int n = v.size();
        bool pos = false , neg = false;
        for( int i = 0 ; i < n ; i++ ) {
            int prev = (i-1+n) % n;
            int next = (i+1) % n;
            int val = ccw(v[prev],v[i],v[next]);
            pos |= (val > 0);
            neg |= (val < 0);
        }
        return (pos ^ neg);
    }
};
