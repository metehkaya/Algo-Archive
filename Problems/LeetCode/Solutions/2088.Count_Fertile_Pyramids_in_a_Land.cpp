class Solution {
public:
    int countPyramids(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<vector<int>> len(n,vector<int>(m,0));
        vector<vector<int>> dpUp(n,vector<int>(m,0));
        vector<vector<int>> dpDown(n,vector<int>(m,0));
        for( int i = 0 ; i < n ; i++ ) {
            for( int l = 0 , r = 0 ; l < m ; l = r+1 ) {
                r = l;
                while(r < m && ar[i][r] == 1)
                    r++;
                if(l != r)
                    for( int j = l ; j < r ; j++ )
                        len[i][j] = min(j-(l-1),r-j);
            }
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    int up = (i == 0) ? 0 : dpUp[i-1][j];
                    dpUp[i][j] = min(len[i][j],up+1);
                    ans += dpUp[i][j]-1;
                }
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    int down = (i == n-1) ? 0 : dpDown[i+1][j];
                    dpDown[i][j] = min(len[i][j],down+1);
                    ans += dpDown[i][j]-1;
                }
        return ans;
    }
};
