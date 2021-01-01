#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    int n,m;
    int dir[4] = {0,1,0,-1};
    const int MOD = 1000000007;
    set<pi> comps;
    void dfs(int r , int c , vector<vector<int>>& ar , vector<pi>& v) {
        ar[r][c] = 0;
        v.push_back(pi(r,c));
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r+dir[i];
            int y = c+dir[i^1];
            if(x < 0 || x >= n || y < 0 || y >= m || ar[x][y] == 0)
                continue;
            dfs(x,y,ar,v);
        }
    }
    void proc(vector<pi>& v) {
        int k = v.size();
        int minR = n , minC = m;
        for( int i = 0 ; i < k ; i++ ) {
            minR = min(minR,v[i].fi);
            minC = min(minC,v[i].se);
        }
        LL val = 0;
        for( int i = 0 ; i < k ; i++ ) {
            int r = v[i].fi-minR;
            int c = v[i].se-minC;
            int num = r*m+c;
            val = (val*n*m+num) % MOD;
        }
        comps.insert(pi(k,val));
    }
    int numDistinctIslands(vector<vector<int>>& ar) {
        n = ar.size();
        if(n == 0)
            return 0;
        m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 1) {
                    vector<pi> v;
                    dfs(i,j,ar,v);
                    proc(v);
                }
        return comps.size();
    }
};