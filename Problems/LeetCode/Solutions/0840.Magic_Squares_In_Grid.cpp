class Solution {
public:
    int n,m,ans;
    vector<vector<int>> ar;
    bool check(int r , int c) {
        int xorsum = 0;
        for( int i = r ; i < r+3 ; i++ )
            for( int j = c ; j < c+3 ; j++ )
                xorsum |= (1 << ar[i][j]);
        if(xorsum != 1022)
            return false;
        set<int> sums;
        sums.insert(ar[r][c]+ar[r][c+1]+ar[r][c+2]);
        sums.insert(ar[r+1][c]+ar[r+1][c+1]+ar[r+1][c+2]);
        sums.insert(ar[r+2][c]+ar[r+2][c+1]+ar[r+2][c+2]);
        sums.insert(ar[r][c]+ar[r+1][c]+ar[r+2][c]);
        sums.insert(ar[r][c+1]+ar[r+1][c+1]+ar[r+2][c+1]);
        sums.insert(ar[r][c+2]+ar[r+1][c+2]+ar[r+2][c+2]);
        sums.insert(ar[r][c]+ar[r+1][c+1]+ar[r+2][c+2]);
        sums.insert(ar[r+2][c]+ar[r+1][c+1]+ar[r][c+2]);
        return sums.size() == 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size();
        m = ar[0].size();
        for( int i = 0 ; i <= n-3 ; i++ )
            for( int j = 0 ; j <= m-3 ; j++ )
                ans += check(i,j);
        return ans;
    }
};