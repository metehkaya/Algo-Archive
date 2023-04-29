class Solution {
public:
    int n;
    vector<string> v;
    vector<vector<string>> ans;
    void f(int row , int maskcol , int masksum , int maskdiff) {
        if(row == n) {
            ans.push_back(v);
            return;
        }
        for( int i = 0 ; i < n ; i++ ) {
            int m1 = i;
            int m2 = row+i;
            int m3 = row-i+(n-1);
            m1 = (1<<m1);
            m2 = (1<<m2);
            m3 = (1<<m3);
            if((maskcol & m1) == 0)
                if((masksum & m2) == 0)
                    if((maskdiff & m3) == 0) {
                        v[row][i] = 'Q';
                        f(row+1,maskcol+m1,masksum+m2,maskdiff+m3);
                        v[row][i] = '.';
                    }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string dots = "";
        for( int i = 0 ; i < n ; i++ )
            dots.push_back('.');
        for( int i = 0 ; i < n ; i++ )
            v.push_back(dots);
        f(0,0,0,0);
        return ans;
    }
};