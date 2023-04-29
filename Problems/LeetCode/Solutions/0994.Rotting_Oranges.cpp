class Solution {
public:
    const int DIR[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& ar) {
        if(ar.size() == 0)
            return 0;
        if(ar[0].size() == 0)
            return 0;
        int n = ar.size();
        int m = ar[0].size();
        int cntF = 0;
        queue<pair<pair<int,int>,int>>Q;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                if(ar[i][j] == 1)
                    cntF++;
                else if(ar[i][j] == 2)
                    Q.push( make_pair( make_pair(i,j) , 0 ) );
            }
        int last = 0;
        while(!Q.empty()) {
            pair<pair<int,int>,int> p = Q.front();
            Q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int d = p.second;
            last = d;
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r + DIR[i][0];
                int c2 = c + DIR[i][1];
                if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                    continue;
                if(ar[r2][c2] == 1) {
                    cntF--;
                    ar[r2][c2] = 2;
                    Q.push( make_pair( make_pair(r2,c2) , d+1 ) );
                }
            }
        }
        if(cntF)
            return -1;
        return last;
    }
};