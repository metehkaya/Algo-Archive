class Solution {
public:
    int ar[500][500];
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int m = mines.size();
        for( int i = 0 ; i < m ; i++ ) {
            int r = mines[i][0];
            int c = mines[i][1];
            ar[r][c] = 1;
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(ar[i][j] == 0) {
                    ans = max(ans,1);
                    int kmax = min( min(i,n-1-i) , min(j,n-1-j) );
                    for( int k = 1 ; k <= kmax ; k++ )
                        if(ar[i-k][j] == 0 && ar[i+k][j] == 0 && ar[i][j-k] == 0 && ar[i][j+k] == 0)
                            ans = max(ans,k+1);
                        else
                            break;
                }
        return ans;
    }
};