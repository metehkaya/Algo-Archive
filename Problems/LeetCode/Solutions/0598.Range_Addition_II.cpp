class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ar) {
        int k = ar.size();
        if(k == 0)
            return n*m;
        int minr = INT_MAX;
        int minc = INT_MAX;
        for( int i = 0 ; i < k ; i++ ) {
            int r = ar[i][0];
            int c = ar[i][1];
            minr = min(minr,r);
            minc = min(minc,c);
        }
        return minr*minc;
    }
};