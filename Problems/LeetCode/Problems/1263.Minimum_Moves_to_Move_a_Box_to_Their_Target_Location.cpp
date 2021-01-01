#define fi first
#define se second
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<viii> viiii;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    const int DIR[4][2] = {{0,-1},{-1,0},{+1,0},{0,+1}};
    void dfs(int rx , int ry , int x , int y , int g , int n , int m , vcc& ar , vii& group) {
        group[x][y] = g;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x2 = x + DIR[i][0];
            int y2 = y + DIR[i][1];
            if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
                continue;
            if(ar[x2][y2] == '#' || group[x2][y2] == g)
                continue;
            if(x == rx && y == ry)
                continue;
            dfs(rx,ry,x2,y2,g,n,m,ar,group);
        }
    }
    int bfs(int n , int m , vcc& ar , viiii& group) {
        int pr,pc,br,bc,fr,fc;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                char c = ar[i][j];
                if(c == 'S')
                    pr = i , pc = j;
                else if(c == 'B')
                    br = i , bc = j;
                else if(c == 'T')
                    fr = i , fc = j;
            }
        queue<pii> Q;
        int dist[n][m][4];
        memset(dist,-1,sizeof(dist));
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = br + DIR[i][0];
            int y = bc + DIR[i][1];
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(ar[x][y] == '#' || group[br][bc][x][y] != group[br][bc][pr][pc])
                continue;
            dist[br][bc][i] = 0;
            Q.push( pii( pi(br,bc) , i ) );
        }
        while(!Q.empty()) {
            pii temp = Q.front();
            Q.pop();
            br = temp.fi.fi;
            bc = temp.fi.se;
            int dir = temp.se;
            if(br == fr && bc == fc)
                return dist[br][bc][dir];
            pr = br + DIR[dir][0];
            pc = bc + DIR[dir][1];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = br + DIR[i][0];
                int y = bc + DIR[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(ar[x][y] == '#' || group[br][bc][x][y] != group[br][bc][pr][pc])
                    continue;
                int x2 = br + DIR[3-i][0];
                int y2 = bc + DIR[3-i][1];
                if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
                    continue;
                if(ar[x2][y2] == '#' || dist[x2][y2][i] != -1)
                    continue;
                dist[x2][y2][i] = dist[br][bc][dir] + 1;
                Q.push( pii( pi(x2,y2) , i ) );
            }
        }
        return -1;
    }
    int minPushBox(vcc& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int g;
        viiii group(n,viii(m));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] != '#') {
                    group[i][j].resize(n,vi(m,-1));
                    g = 0;
                    for( int x = 0 ; x < n ; x++ )
                        for( int y = 0 ; y < m ; y++ )
                            if(group[i][j][x][y] == -1 && ar[x][y] != '#' && (x != i || y != j)) {
                                g++;
                                dfs(i,j,x,y,g,n,m,ar,group[i][j]);
                            }
                }
        return bfs(n,m,ar,group);
    }
};