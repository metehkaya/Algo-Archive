class Solution {
public:
    bool searchMatrix(vector<vector<int>>& ar, int target) {
        int n = ar.size();
        if(n == 0)
            return false;
        int m = ar[0].size();
        if(m == 0)
            return false;
        int row = n-1;
        int col = 0;
        while(row >= 0 && col < m) {
            if(ar[row][col] == target)
                return true;
            else if(ar[row][col] < target)
                col++;
            else
                row--;
        }
        return false;
    }
};