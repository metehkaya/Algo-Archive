class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector< vector<char> > s(m,vector<char>(n));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                s[j][n-1-i] = box[i][j];
        swap(n,m);
        for( int j = 0 ; j < m ; j++ ) {
            int cntb = 0;
            int cnte = 0;
            for( int i = n-1 ; i >= 0 ; i-- ) {
                if(s[i][j] == '#')
                    cntb++;
                else if(s[i][j] == '.')
                    cnte++;
                else {
                    if(cntb)
                        for( int i2 = 0 ; i2 < cntb+cnte ; i2++ ) {
                            if(i2 < cntb)
                                s[i+cntb+cnte-i2][j] = '#';
                            else
                                s[i+cntb+cnte-i2][j] = '.';
                        }
                    cntb = cnte = 0;
                }
            }
            int i = -1;
            if(cntb)
                for( int i2 = 0 ; i2 < cntb+cnte ; i2++ ) {
                    if(i2 < cntb)
                        s[i+cntb+cnte-i2][j] = '#';
                    else
                        s[i+cntb+cnte-i2][j] = '.';
                }
        }
        return s;
    }
};