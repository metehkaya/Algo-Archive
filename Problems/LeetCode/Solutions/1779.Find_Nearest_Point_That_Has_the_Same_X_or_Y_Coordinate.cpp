class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& ar) {
        int n = ar.size();
        int minDist = INT_MAX , ans = -1;
        for( int i = 0 ; i < n ; i++ ) {
            int a = ar[i][0];
            int b = ar[i][1];
            if(x == a || y == b) {
                int dist = abs(x-a) + abs(y-b);
                if(dist < minDist) {
                    ans = i;
                    minDist = dist;
                }
            }
        }
        return ans;
    }
};