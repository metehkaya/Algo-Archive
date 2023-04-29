#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    int n,m,k,K;
    vector<string> ar;
    int dist[30][30][64];
    int dir[4] = {0,1,0,-1};
    int shortestPathAllKeys(vector<string>& ar) {
        this->ar = ar;
        n = ar.size();
        m = ar[0].length();
        int r,c;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                if(ar[i][j] == '@')
                    r = i , c = j;
                else if(ar[i][j] >= 'a' && ar[i][j] <= 'z')
                    k = max(k,ar[i][j]-'a'+1);
            }
        K = (1<<k);
        memset(dist,-1,sizeof(dist));
        queue<pii> q;
        q.push(pii(pi(r,c),0));
        dist[r][c][0] = 0;
        while(!q.empty()) {
            pii temp = q.front();
            q.pop();
            r = temp.fi.fi;
            c = temp.fi.se;
            int bmask = temp.se;
            if(bmask == K-1)
                return dist[r][c][bmask];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i];
                int y = c + dir[i^1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(ar[x][y] == '#')
                    continue;
                int bmask2 = bmask;
                if(ar[x][y] >= 'a' && ar[x][y] <= 'z')
                    bmask2 |= (1 << (ar[x][y]-'a'));
                else if(ar[x][y] >= 'A' && ar[x][y] <= 'Z') {
                    int id = ar[x][y] - 'A';
                    if((bmask & (1<<id)) == 0)
                        continue;
                }
                if(dist[x][y][bmask2] != -1)
                    continue;
                q.push(pii(pi(x,y),bmask2));
                dist[x][y][bmask2] = dist[r][c][bmask]+1;
            }
        }
        return -1;
    }
};