class Solution {
public:
    int gcd(int x, int y) {
        if(!y)
            return x;
        return gcd(y, x%y);
    }
    void simplify(int& diffX, int& diffY) {
        if(diffX < 0)
            diffX = -diffX, diffY = -diffY;
        int g = gcd(diffX, diffY);
        diffX /= g;
        diffY /= g;
    }
    bool checkStraightLine(vector<vector<int>>& ar) {
        int n = ar.size();
        int diffX = ar[1][0] - ar[0][0];
        int diffY = ar[1][1] - ar[0][1];
        simplify(diffX, diffY);
        for( int i = 2 ; i < n ; i++ ) {
            int dX = ar[i][0] - ar[0][0];
            int dY = ar[i][1] - ar[0][1];
            simplify(dX, dY);
            if(diffY * dX != diffX * dY)
                return false;
        }
        return true;
    }
};