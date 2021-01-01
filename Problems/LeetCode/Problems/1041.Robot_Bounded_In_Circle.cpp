class Solution {
public:
    const int DIR[4][2] = {{0,+1},{+1,0},{0,-1},{-1,0}};
    bool isRobotBounded(string s) {
        int x=0 , y=0 , dir=0;
        int n = s.length();
        for( int i = 0 ; i < 4*n ; i++ ) {
            char c = s[i%n];
            if(c == 'G')
                x += DIR[dir][0] , y += DIR[dir][1];
            else if(c == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }
        return x == 0 && y == 0;
    }
};