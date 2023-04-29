#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int trapRainWater(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size() , ans = 0;
        priority_queue<pii,vector<pii>,greater<pii>> heap;
        for( int i = 0 ; i < n ; i++ ) {
            heap.push(pii(ar[i][0],pi(i,0)));
            heap.push(pii(ar[i][m-1],pi(i,m-1)));
        }
        for( int j = 0 ; j < m ; j++ ) {
            heap.push(pii(ar[0][j],pi(0,j)));
            heap.push(pii(ar[n-1][j],pi(n-1,j)));
        }
        bool mark[n][m];
        memset(mark,false,sizeof(mark));
        while(!heap.empty()) {
            pii temp = heap.top();
            heap.pop();
            int d = temp.fi;
            int r = temp.se.fi;
            int c = temp.se.se;
            if(mark[r][c])
                continue;
            mark[r][c] = true;
            ans += max(d-ar[r][c],0);
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i];
                int y = c+dir[i^1];
                if(x < 0 || x >= n || y < 0 || y >= m || mark[x][y])
                    continue;
                int val = max(d,ar[x][y]);
                heap.push(pii(val,pi(x,y)));
            }
        }
        return ans;
    }
};
