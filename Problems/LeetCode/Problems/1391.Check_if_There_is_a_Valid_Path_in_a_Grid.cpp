struct Pos {
    int r,c,end;
    Pos( int _r , int _c , int _end ) {
        r = _r;
        c = _c;
        end = _end;
    }
};

class Solution {
public:
    vector<vector<Pos>> calcPos() {
        vector<vector<Pos>> nextPos( 6 , vector<Pos>( 4 , Pos(-1,-1,-1) ) );
        nextPos[0][0] = Pos(0,1,0);
        nextPos[0][2] = Pos(0,-1,2);
        nextPos[1][1] = Pos(1,0,1);
        nextPos[1][3] = Pos(-1,0,3);
        nextPos[2][0] = Pos(1,0,1);
        nextPos[2][3] = Pos(0,-1,2);
        nextPos[3][2] = Pos(1,0,1);
        nextPos[3][3] = Pos(0,1,0);
        nextPos[4][0] = Pos(-1,0,3);
        nextPos[4][1] = Pos(0,-1,2);
        nextPos[5][1] = Pos(0,1,0);
        nextPos[5][2] = Pos(-1,0,3);
        return nextPos;
    }
    bool solve( int end , vector<vector<Pos>>& nextPos , vector<vector<int>>& ar ) {
        int r = 0 , c = 0 , n = ar.size() , m = ar[0].size();
        bool mark[n][m][4];
        memset(mark,false,sizeof(mark));
        while(r >= 0 && r < n && c >= 0 && c < m) {
            int type = ar[r][c] - 1;
            if(r == n-1 && c == m-1)
                return nextPos[type][end].end != -1;
            if(mark[r][c][end])
                return false;
            mark[r][c][end] = true;
            if(nextPos[type][end].end == -1)
                return false;
            r += nextPos[type][end].r;
            c += nextPos[type][end].c;
            end = nextPos[type][end].end;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        if(n == 1 && m == 1)
            return true;
        vector<vector<Pos>> nextPos = calcPos();
        for( int end = 0 ; end < 4 ; end++ )
            if( solve(end,nextPos,ar) )
                return true;
        return false;
    }
};