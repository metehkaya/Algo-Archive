typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& ar) {
        queue<pii> Q;
        int n = ar.size();
        int dist[n][n][4];
        memset(dist,-1,sizeof(dist));
        dist[0][0][0] = 0;
        Q.push(pii(pi(0,0),0));
        while(!Q.empty()) {
            pii temp = Q.front();
            Q.pop();
            int r1 = temp.first.first;
            int c1 = temp.first.second;
            int dir = temp.second;
            if(r1 == n-1 && c1 == n-2 && dir == 0)
                return dist[r1][c1][dir];
            int r2,c2;
            if(dir == 0)
                r2 = r1 , c2 = c1+1;
            else
                r2 = r1+1 , c2 = c1;
            if(c2+1 < n && !ar[r1][c1+1] && !ar[r2][c2+1] && dist[r1][c1+1][dir] == -1) {
                Q.push(pii(pi(r1,c1+1),dir));
                dist[r1][c1+1][dir] = dist[r1][c1][dir] + 1;
            }
            if(r2+1 < n && !ar[r1+1][c1] && !ar[r2+1][c2] && dist[r1+1][c1][dir] == -1) {
                Q.push(pii(pi(r1+1,c1),dir));
                dist[r1+1][c1][dir] = dist[r1][c1][dir] + 1;
            }
            if(r1+1 < n && dir == 0 && !ar[r1+1][c1] && !ar[r1+1][c1+1] && dist[r1][c1][1] == -1) {
                Q.push(pii(pi(r1,c1),1));
                dist[r1][c1][1] = dist[r1][c1][0] + 1;
            }
            if(c1+1 < n && dir == 1 && !ar[r1][c1+1] && !ar[r1+1][c1+1] && dist[r1][c1][0] == -1) {
                Q.push(pii(pi(r1,c1),0));
                dist[r1][c1][0] = dist[r1][c1][1] + 1;
            }
        }
        return -1;
    }
};