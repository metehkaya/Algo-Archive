#define fi first
#define se second
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;

class Solution {
public:
    int n,m;
    int ans,total=0;
    int dir[4] = {0,1,0,-1};
    void bfs(int x , int y , vii& ar , vii& cnt , vii& cost) {
        bool mark[n][m];
        memset(mark,false,sizeof(mark));
        queue<pi> Q;
        Q.push(pi(x,y));
        mark[x][y] = true;
        int dist = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                pi temp = Q.front();
                Q.pop();
                x = temp.fi;
                y = temp.se;
                cnt[x][y]++;
                cost[x][y] += dist;
                for( int i = 0 ; i < 4 ; i++ ) {
                    int r = x + dir[i];
                    int c = y + dir[i^1];
                    if(r >= 0 && r < n && c >= 0 && c < m)
                        if(!mark[r][c] && !ar[r][c]) {
                            Q.push(pi(r,c));
                            mark[r][c] = true;
                        }
                }
            }
            dist++;
        }
    }
    int shortestDistance(vector<vector<int>>& ar) {
        n = ar.size();
        m = ar[0].size();
        vii cnt(n,vi(m,0));
        vii cost(n,vi(m,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 1) {
                    total++;
                    bfs(i,j,ar,cnt,cost);
                }
        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(!ar[i][j] && cnt[i][j] == total)
                    ans = min(ans,cost[i][j]);
        return (ans != INT_MAX) ? ans : -1;
    }
};