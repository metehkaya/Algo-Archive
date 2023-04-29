#define fi first
#define se second
#define maxn 150
#define maxk (maxn*maxn)
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int n,m,k;
    int group[maxn][maxn];
    bool isOcean[maxk][2];
    bool mark[maxk][2];
    vector<int> adj[maxk];
    vector<vector<int>> ar;
    vector<pi> cells[maxk];
    vector<vector<int>> ans;
    int dir[4] = {0,1,0,-1};
    void add(int r , int c) {
        vector<int> v;
        v.pb(r);
        v.pb(c);
        ans.pb(v);
    }
    void dfs(int r , int c , int val) {
        group[r][c] = k;
        cells[k].pb(pi(r,c));
        if(r == 0 || c == 0)
            isOcean[k][0] = true;
        if(r == n-1 || c == m-1)
            isOcean[k][1] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i];
            int y = c + dir[i^1];
            if(x >= 0 && x < n && y >= 0 && y < m)
                if(group[x][y] == -1 && ar[x][y] == val)
                    dfs(x,y,val);
        }
    }
    void dfs(int u , int type) {
        mark[u][type] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v][type])
                dfs(v,type);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ar) {
        this->ar = ar;
        n = ar.size();
        if(n == 0)
            return ans;
        m = ar[0].size();
        memset(group,-1,sizeof(group));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(group[i][j] == -1) {
                    dfs(i,j,ar[i][j]);
                    k++;
                }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                for( int d = 0 ; d < 4 ; d++ ) {
                    int x = i + dir[d];
                    int y = j + dir[d^1];
                    if(x >= 0 && x < n && y >= 0 && y < m)
                        if(ar[i][j] < ar[x][y])
                            adj[group[i][j]].pb(group[x][y]);
                }
        for( int i = 0 ; i < k ; i++ )
            if(isOcean[i][0] && !mark[i][0])
                dfs(i,0);
        for( int i = 0 ; i < k ; i++ )
            if(isOcean[i][1] && !mark[i][1])
                dfs(i,1);
        for( int i = 0 ; i < k ; i++ )
            if(mark[i][0] && mark[i][1]) {
                int sz = cells[i].size();
                for( int j = 0 ; j < sz ; j++ )
                    add(cells[i][j].fi,cells[i][j].se);
            }
        return ans;
    }
};