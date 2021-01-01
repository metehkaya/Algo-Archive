class Solution {
public:
    bool searchMatrix(vector<vector<int>>& ar, int t) {
        int n = ar.size();
        if(n == 0)
            return false;
        int m = ar[0].size();
        if(m == 0)
            return false;
        int l = 0 , r = n*m-1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int row = mid/m;
            int col = mid%m;
            if(ar[row][col] == t)
                return true;
            else if(ar[row][col] < t)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};