typedef pair<int,int> pi;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& ar) {
        queue<pi> Q;
        int n = ar.size();
        if(ar[0][0] == 1 || ar[n-1][n-1] == 1)
            return -1;
        vector<vector<int>> dist(n,vector<int>(n,-1));
        dist[0][0] = 0;
        Q.push(pi(0,0));
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int r = temp.first;
            int c = temp.second;
            for( int i = -1 ; i <= +1 ; i++ )
                for( int j = -1 ; j <= +1 ; j++ )
                    if(i != 0 || j != 0) {
                        int r2 = r+i , c2 = c+j;
                        if(r2 < 0 || r2 == n || c2 < 0 || c2 == n)
                            continue;
                        if(dist[r2][c2] != -1 || ar[r2][c2] == 1)
                            continue;
                        Q.push(pi(r2,c2));
                        dist[r2][c2] = dist[r][c] + 1;
                    }
        }
        int ans = dist[n-1][n-1];
        return (ans == -1) ? -1 : ans+1;
    }
};