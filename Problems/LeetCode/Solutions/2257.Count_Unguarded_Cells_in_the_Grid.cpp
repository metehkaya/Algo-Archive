#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int n,m;
    void f(int r , int c , int dr , int dc , vector<vector<int>>& ar) {
        bool g = false;
        while(r >= 0 && r < n && c >= 0 && c < m) {
            if(ar[r][c] == 0 && g)
                ar[r][c] = 3;
            if(ar[r][c] == 1)
                g = true;
            else if(ar[r][c] == 2)
                g = false;
            r += dr , c += dc;
        }
    }
    int countUnguarded(int n, int m, vector<vector<int>>& g, vector<vector<int>>& w) {
        this->n = n;
        this->m = m;
        vector<vector<int>> ar(n,vector<int>(m,0));
        for( int i = 0 ; i < g.size() ; i++ )
            ar[g[i][0]][g[i][1]] = 1;
        for( int i = 0 ; i < w.size() ; i++ )
            ar[w[i][0]][w[i][1]] = 2;
        for( int i = 0 ; i < n ; i++ ) {
            f(i,0,0,1,ar);
            f(i,m-1,0,-1,ar);
        }
        for( int i = 0 ; i < m ; i++ ) {
            f(0,i,1,0,ar);
            f(n-1,i,-1,0,ar);
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans += !ar[i][j];
        return ans;
    }
};
