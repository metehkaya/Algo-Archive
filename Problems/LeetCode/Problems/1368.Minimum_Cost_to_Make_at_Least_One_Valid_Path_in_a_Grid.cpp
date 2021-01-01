#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int maxCost = n+m-1;
        queue<pi> Q[maxCost];
        bool mark[maxCost][n][m];
        memset(mark,false,sizeof(mark));
        Q[0].push(pi(0,0));
        mark[0][0][0] = true;
        for( int cost = 0 ; cost < maxCost ; cost++ ) {
            while(!Q[cost].empty()) {
                pi temp = Q[cost].front();
                Q[cost].pop();
                int r = temp.fi;
                int c = temp.se;
                if(r == n-1 && c == m-1)
                    return cost;
                int type = ar[r][c]-1;
                for( int i = 0 ; i < 4 ; i++ ) {
                    int r2 = r+DIR[i][0];
                    int c2 = c+DIR[i][1];
                    int cost2 = cost+(type!=i);
                    if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                        continue;
                    if(cost2 == maxCost || mark[cost2][r2][c2])
                        continue;
                    mark[cost2][r2][c2] = true;
                    Q[cost2].push(pi(r2,c2));
                }
            }
        }
        return -1;
    }
};