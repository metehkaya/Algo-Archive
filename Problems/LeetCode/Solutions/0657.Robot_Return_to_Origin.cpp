class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        int n = moves.size();
        for( int i = 0 ; i < n ; i++ ) {
            char c = moves[i];
            if(c == 'L') x--;
            if(c == 'R') x++;
            if(c == 'U') y++;
            if(c == 'D') y--;
        }
        return x==0 && y==0;
    }
};