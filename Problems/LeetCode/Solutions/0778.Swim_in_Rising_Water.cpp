#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int n;
    bool mark[50][50];
    vector<vector<int>> ar;
    int dir[4] = {0,1,0,-1};
    bool check(int mx) {
        queue<pi> Q;
        memset(mark,false,sizeof(mark));
        Q.push(pi(0,0));
        mark[0][0] = true;
        while(!Q.empty()) {
            pi p = Q.front();
            Q.pop();
            int r = p.fi;
            int c = p.se;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i];
                int y = c + dir[i^1];
                if(x < 0 || x >= n || y < 0 || y >= n)
                    continue;
                if(mark[x][y] || ar[x][y] > mx)
                    continue;
                Q.push(pi(x,y));
                mark[x][y] = true;
            }
        }
        return mark[n-1][n-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        ar = grid;
        n = ar.size();
        int l = ar[0][0] , r = n*n-1 , ans = n*n;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(check(m))
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};