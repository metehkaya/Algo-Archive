#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int shortestDistance(vii& ar, vi& src, vi& dest) {
        int n = ar.size() , m = ar[0].size();
        viii dist(n,vii(m,vi(4,-1)));
        queue<pii> Q;
        for( int i = 0 ; i < 4 ; i++ ) {
            Q.push(pii(pi(src[0],src[1]),i));
            dist[src[0]][src[1]][i] = 0;
        }
        int ans = -1;
        while(!Q.empty()) {
            pii temp = Q.front();
            Q.pop();
            int r = temp.fi.fi;
            int c = temp.fi.se;
            int d = temp.se;
            bool ch = false;
            int R = r + dir[d] , C = c + dir[d^1];
            if(R < 0 || R >= ar.size() || C < 0 || C >= ar[0].size() || ar[R][C])
                ch = true;
            if(r == dest[0] && c == dest[1] && ch) {
                ans = dist[r][c][d];
                break;
            }
            if(!ch) {
                if(dist[R][C][d] == -1) {
                    Q.push(pii(pi(R,C),d));
                    dist[R][C][d] = dist[r][c][d]+1;
                }
            }
            else {
                for( int i = 0 ; i < 4 ; i++ ) {
                    int R = r + dir[i] , C = c + dir[i^1];
                    if(R < 0 || R >= ar.size() || C < 0 || C >= ar[0].size() || ar[R][C])
                        continue;
                    if(dist[R][C][i] == -1) {
                        Q.push(pii(pi(R,C),i));
                        dist[R][C][i] = dist[r][c][d]+1;
                    }
                }
            }
        }
        return ans;
    }
};