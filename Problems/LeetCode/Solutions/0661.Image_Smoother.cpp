class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<int>> ans = ar;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int sum = 0 , cnt = 0;
                for( int r = -1 ; r <= 1 ; r++ )
                    for( int c = -1 ; c <= 1 ; c++ ) {
                        int x = i+r , y = j+c;
                        if(x >= 0 && x < n && y >= 0 && y < m)
                            cnt++ , sum += ar[x][y];
                    }
                ans[i][j] = sum/cnt;
            }
        return ans;
    }
};