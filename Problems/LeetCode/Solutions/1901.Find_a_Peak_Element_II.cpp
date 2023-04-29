class Solution {
public:
    int n,m;
    vector<vector<int>> ar;
    int getMax(int row) {
        int col = 0;
        for( int i = 1 ; i < m ; i++ )
            if(ar[row][i] > ar[row][col])
                col = i;
        return col;
    }
    vector<int> findPeakGrid(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size();
        m = ar[0].size();
        vector<int> ans(2,-1);
        int l = 0 , r = n-1;
        while(l <= r) {
            int row = (l+r) >> 1;
            int col = getMax(row);
            bool biggerThanAbove = (row == 0) ? true : ar[row][col] > ar[row-1][col];
            bool biggerThanBelow = (row == n-1) ? true : ar[row][col] > ar[row+1][col];
            if(biggerThanAbove and biggerThanBelow) {
                ans[0] = row;
                ans[1] = col;
                break;
            }
            if(!biggerThanAbove)
                r = row-1;
            else
                l = row+1;
        }
        return ans;
    }
};
