class Solution {
public:
    const int dir[4] = {0,1,0,-1};
    int numRookCaptures(vector<vector<char>>& ar) {
        int ans=0;
        for( int i = 0 ; i < 8 ; i++ )
            for( int j = 0 ; j < 8 ; j++ )
                if(ar[i][j] == 'R') {
                    for( int d = 0 ; d < 4 ; d++ )
                        for( int k = 1 ; k < 8 ; k++ ) {
                            int x = i + k*dir[d];
                            int y = j + k*dir[d^1];
                            if(x == -1 or x == 8 or y == -1 or y == 8)
                                break;
                            if(ar[x][y] != '.') {
                                if(ar[x][y] == 'p')
                                    ans++;
                                break;
                            }
                        }
                }
        return ans;
    }
};