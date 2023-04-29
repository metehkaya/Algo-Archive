class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int surfaceArea(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    ans += 2;
                    for( int k = 0 ; k < 4 ; k++ ) {
                        int r = i + dir[k];
                        int c = j + dir[k^1];
                        if(r < 0 || r == n || c < 0 || c == m)
                            ans += ar[i][j];
                        else
                            ans += ar[i][j] - min(ar[i][j],ar[r][c]);
                    }
                }
        return ans;
    }
};