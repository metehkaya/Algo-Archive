class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& ar) {
        int n = ar.size();
        int best = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int x = min(ar[i][0],ar[i][1]);
            if(x > best)
                best = x , ans = 1;
            else if(x == best)
                ans++;
        }
        return ans;
    }
};