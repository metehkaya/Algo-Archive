#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int n,m;
    int day[20001];
    int dir[4] = {0,1,0,-1};
    int id(int r , int c) {
        return r*m+c;
    }
    bool check(int d) {
        queue<pi> q;
        bool mark[n][m];
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < m ; i++ )
            if(d < day[id(0,i)]) {
                q.push(pi(0,i));
                mark[0][i] = true;
            }
        while(!q.empty()) {
            pi p = q.front();
            q.pop();
            int r = p.fi;
            int c = p.se;
            if(r == n-1)
                return true;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i];
                int y = c + dir[i^1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(mark[x][y] || d >= day[id(x,y)])
                    continue;
                q.push(pi(x,y));
                mark[x][y] = true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& ar) {
        n = row;
        m = col;
        for( int i = 0 ; i < n*m ; i++ ) {
            int r = ar[i][0];
            int c = ar[i][1];
            r--,c--;
            day[id(r,c)] = i+1;
        }
        int l = 1 , r = n*m , ans = 0;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid))
                ans = mid , l = mid+1;
            else
                r = mid-1;
        }
        return ans;
    }
};