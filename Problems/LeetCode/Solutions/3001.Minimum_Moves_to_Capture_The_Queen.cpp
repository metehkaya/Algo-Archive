class Solution {
public:
    int rdir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int bdir[4][2] = {{-1,-1},{1,1},{1,-1},{-1,1}};
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        for( int i = 0 ; i < 4 ; i++ )
            for( int k = 1 ; k <= 7 ; k++ ) {
                int dx = rdir[i][0] , dy = rdir[i][1];
                if(a+dx*k == c && b+dy*k == d)
                    break;
                if(a+dx*k == e && b+dy*k == f)
                    return 1;
            }
        for( int i = 0 ; i < 4 ; i++ )
            for( int k = 1 ; k <= 7 ; k++ ) {
                int dx = bdir[i][0] , dy = bdir[i][1];
                if(c+dx*k == a && d+dy*k == b)
                    break;
                if(c+dx*k == e && d+dy*k == f)
                    return 1;
            }
        return 2;
    }
};
