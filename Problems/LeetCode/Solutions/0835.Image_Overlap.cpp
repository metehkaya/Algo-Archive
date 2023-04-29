class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size() , ans = 0;
        for( int x = -(n-1) ; x < n ; x++ )
            for( int y = -(n-1) ; y < n ; y++ ) {
                int cnt = 0;
                for( int i = 0 ; i < n ; i++ )
                    for( int j = 0 ; j < n ; j++ ) {
                        int r = (i+x);
                        int c = (j+y);
                        if(r >= 0 && r < n && c >= 0 && c < n)
                            cnt += A[i][j]*B[r][c];
                    }
                ans = max(ans,cnt);
            }
        return ans;
    }
};