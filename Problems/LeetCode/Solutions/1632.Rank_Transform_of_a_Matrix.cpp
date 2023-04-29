#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Solution {
public:
    int n,m,mx;
    int mxrow[500];
    int mxcol[500];
    bool mark[500][500];
    vector<pi> visited;
    vector<vector<int>> ar;
    vector<pi> adj[500][500];
    void graphRow(int i) {
        map<int,int> mp;
        map<int,int>::iterator it;
        for( int j = 0 ; j < m ; j++ ) {
            it = mp.find(ar[i][j]);
            if(it != mp.end()) {
                int old = (*it).second;
                adj[i][old].pb(pi(i,j));
                adj[i][j].pb(pi(i,old));
            }
            mp[ar[i][j]] = j;
        }
    }
    void graphCol(int j) {
        map<int,int> mp;
        map<int,int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            it = mp.find(ar[i][j]);
            if(it != mp.end()) {
                int old = (*it).second;
                adj[old][j].pb(pi(i,j));
                adj[i][j].pb(pi(old,j));
            }
            mp[ar[i][j]] = i;
        }
    }
    void dfs(int r , int c) {
        mark[r][c] = true;
        visited.pb(pi(r,c));
        mx = max(mx,mxrow[r]);
        mx = max(mx,mxcol[c]);
        int sz = adj[r][c].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int x = adj[r][c][i].fi;
            int y = adj[r][c][i].se;
            if(!mark[x][y])
                dfs(x,y);
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        ar = matrix;
        n = ar.size();
        m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            graphRow(i);
        for( int j = 0 ; j < m ; j++ )
            graphCol(j);
        vector<pii> v;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                v.pb(pii(ar[i][j],pi(i,j)));
        sort(v.begin(),v.end());
        for( int k = 0 ; k < n*m ; k++ ) {
            int i = v[k].se.fi;
            int j = v[k].se.se;
            if(!mark[i][j]) {
                mx = 0;
                visited.clear();
                dfs(i,j);
                int res = mx+1;
                int sz = visited.size();
                for( int s = 0 ; s < sz ; s++ ) {
                    int r = visited[s].fi;
                    int c = visited[s].se;
                    ans[r][c] = res;
                    mxrow[r] = max(mxrow[r],res);
                    mxcol[c] = max(mxcol[c],res);
                }
            }
        }
        return ans;
    }
};