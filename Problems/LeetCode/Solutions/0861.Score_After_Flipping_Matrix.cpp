class Solution {
public:
    int n,m,ans;
    vector<vector<int>> ar;
    void changeRow(int i) {
        for( int j = 0 ; j < m ; j++ )
            ar[i][j] = 1-ar[i][j];
    }
    void changeCol(int j) {
        for( int i = 0 ; i < n ; i++ )
            ar[i][j] = 1-ar[i][j];
    }
    int matrixScore(vector<vector<int>>& mat) {
        ar = mat;
        n = ar.size();
        m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][0] == 0)
                changeRow(i);
        for( int j = 0 ; j < m ; j++ ) {
            int cnt[2] = {0,0};
            for( int i = 0 ; i < n ; i++ )
                cnt[ar[i][j]]++;
            if(cnt[0] > cnt[1])
                changeCol(j);
        }
        for( int i = 0 ; i < n ; i++ ) {
            int val = 0;
            for( int j = 0 ; j < m ; j++ )
                val = 2*val + ar[i][j];
            ans += val;
        }
        return ans;
    }
};