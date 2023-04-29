class Solution {
public:
    int dir[8][2] = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
    bool checkValidGrid(vector<vector<int>>& v) {
        int n = v.size() , r = 0 , c = 0;
        if(v[0][0])
            return false;
        for( int i = 1 ; i < n*n ; i++ ) {
            bool ok = false;
            for( int k = 0 ; k < 8 ; k++ ) {
                int x = r+dir[k][0] , y = c+dir[k][1];
                if(x >= 0 and x < n and y >= 0 and y < n and v[x][y] == i) {
                    ok = true;
                    r = x , c = y;
                    break;
                }
            }
            if(!ok)
                return false;
        }
        return true;
    }
};
