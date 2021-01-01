class Solution {
public:
    int dir[8][2] = {{-1,-1},{-1,0},{-1,+1},{+1,-1},{+1,0},{+1,+1},{0,-1},{0,+1}};
    void gameOfLife(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int cnt = 0;
                for( int k = 0 ; k < 8 ; k++ ) {
                    int r = i+dir[k][0];
                    int c = j+dir[k][1];
                    if(r < 0 || r >= n || c < 0 || c >= m)
                        continue;
                    if(ar[r][c] & 1)
                        cnt++;
                }
                if(ar[i][j] && (cnt<2 || cnt>3))
                    ar[i][j] = 3;
                else if(!ar[i][j] && cnt == 3)
                    ar[i][j] = 2;
            }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] >= 2)
                    ar[i][j] = 3-ar[i][j];
    }
};