#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int n,m;
    int dir[4] = {0,1,0,-1};
    vector<vector<int>> ar;
    void bfsFire(vector<vector<int>>& distFire) {
        queue<pi> q;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 1) {
                    q.push(pi(i,j));
                    distFire[i][j] = 0;
                }
        while(!q.empty()) {
            pi p = q.front();
            q.pop();
            int r = p.fi;
            int c = p.se;
            int d = distFire[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r+dir[i];
                int c2 = c+dir[i^1];
                if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                    continue;
                if(ar[r2][c2] != 0 || distFire[r2][c2] != -1)
                    continue;
                q.push(pi(r2,c2));
                distFire[r2][c2] = d+1;
            }
        }
    }
    bool bfs(int before, vector<vector<int>>& distFire) {
        queue<pi> q;
        q.push(pi(0,0));
        vector<vector<int>> dist(n,vector<int>(m,-1));
        dist[0][0] = before;
        while(!q.empty()) {
            pi p = q.front();
            q.pop();
            int r = p.fi;
            int c = p.se;
            if(r == n-1 && c == m-1)
                return true;
            int d = dist[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r+dir[i];
                int c2 = c+dir[i^1];
                if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                    continue;
                if(ar[r2][c2] != 0 || dist[r2][c2] != -1)
                    continue;
                if(distFire[r2][c2] != -1 && distFire[r2][c2] < d+1)
                    continue;
                if((r2 != n-1 || c2 != m-1) && distFire[r2][c2] == d+1)
                    continue;
                q.push(pi(r2,c2));
                dist[r2][c2] = d+1;
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size() , m = ar[0].size();
        vector<vector<int>> distFire(n,vector<int>(m,-1));
        bfsFire(distFire);
        int l = 0 , r = (int)1e9 , ans = -1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(bfs(mid,distFire))  {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};
