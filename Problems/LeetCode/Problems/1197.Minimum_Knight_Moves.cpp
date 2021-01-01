typedef pair<int,int> pi;

class Solution {
public:
    const int ADD = 302;
    const int LIM = 603;
    const int DIR[8][2] = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
    int minKnightMoves(int x, int y) {
        vector<vector<int>> dist(LIM,vector<int>(LIM,-1));
        queue<pi> Q;
        Q.push(pi(ADD,ADD));
        dist[ADD][ADD] = 0;
        x += ADD , y += ADD;
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.first;
            int c = temp.second;
            if(r == x && c == y)
                return dist[r][c];
            for( int i = 0 ; i < 8 ; i++ ) {
                int rr = r + DIR[i][0];
                int cc = c + DIR[i][1];
                if(rr < 0 || rr >= LIM || cc < 0 || cc >= LIM)
                    continue;
                if(dist[rr][cc] != -1)
                    continue;
                Q.push(pi(rr,cc));
                dist[rr][cc] = dist[r][c] + 1;
            }
        }
        return -1;
    }
};