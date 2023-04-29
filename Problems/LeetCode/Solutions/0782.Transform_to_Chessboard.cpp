class Solution {
public:
    int n;
    bool check(vector<vector<int>>& ar) {
        int cntSame = 1 , cntDiff = 0;
        for( int i = 1 ; i < n ; i++ ) {
            if(ar[i][0] == ar[0][0]) {
                cntSame++;
                for( int j = 1 ; j < n ; j++ )
                    if(ar[i][j] != ar[0][j])
                        return true;
            }
            else {
                cntDiff++;
                for( int j = 1 ; j < n ; j++ )
                    if(ar[i][j] == ar[0][j])
                        return true;
            }
        }
        return abs(cntSame-cntDiff) > 1;
    }
    int movesToChessboard(vector<vector<int>>& ar) {
        n = ar.size();
        vector<vector<int>> ar_t(n,vector<int>(n));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                ar_t[i][j] = ar[j][i];
        if(check(ar) || check(ar_t))
            return -1;
        int cntRow = 0 , cntCol = 0;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][0] != i%2)
                cntRow++;
        for( int i = 0 ; i < n ; i++ )
            if(ar[0][i] != i%2)
                cntCol++;
        int ans = 0;
        if(n % 2) {
            if(cntRow % 2)
                cntRow = n-cntRow;
            if(cntCol % 2)
                cntCol = n-cntCol;
            ans += cntRow / 2;
            ans += cntCol / 2;
        }
        else {
            ans += min(cntRow,n-cntRow) / 2;
            ans += min(cntCol,n-cntCol) / 2;
        }
        return ans;
    }
};