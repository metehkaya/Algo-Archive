typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4][2] = {{0,+1},{0,-1},{+1,0},{-1,0}};
    bool check(vector<vector<int>>& ar , int n , int m , int limit) {
        queue<pi> Q;
        bool mark[n][m];
        memset(mark,false,sizeof(mark));
        Q.push(pi(0,0));
        mark[0][0] = true;
        while(!Q.empty()) {
            pi p = Q.front();
            Q.pop();
            int r = p.first;
            int c = p.second;
            if(r == n-1 && c == m-1)
                return true;
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r + DIR[i][0];
                int c2 = c + DIR[i][1];
                if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                    continue;
                if(mark[r2][c2] || ar[r2][c2] < limit)
                    continue;
                mark[r2][c2] = true;
                Q.push(pi(r2,c2));
            }
        }
        return false;
    }
    int maximumMinimumPath(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int ans = 0;
        int l = 1 , r = min(ar[0][0],ar[n-1][m-1]);
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(ar,n,m,mid))
                ans = mid , l = mid+1;
            else
                r = mid-1;
        }
        return ans;
    }
};