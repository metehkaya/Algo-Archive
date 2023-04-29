#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;

class Solution {
public:
    vector<int> roots;
    int best = INT_MAX;
    void dfs(int u , int dad , vector<int>& h , vector<vi>& adj , vector<pii>& vec) {
        h[u] = 0;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(v == dad)
                continue;
            dfs(v,u,h,adj,vec);
            int hc = h[v]+1;
            h[u] = max(h[u],hc);
            if(hc >= vec[u].fi.se) {
                vec[u].se = vec[u].fi;
                vec[u].fi = pi(v,hc);
            }
            else if(hc >= vec[u].se.se)
                vec[u].se = pi(v,hc);
        }
    }
    void solve(int u , int dad , int up , vector<int>& h , vector<vi>& adj , vector<pii>& vec) {
        int height = max(h[u],up);
        if(height < best) {
            best = height;
            roots.clear();
            roots.pb(u);
        }
        else if(height == best)
            roots.pb(u);
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(v == dad)
                continue;
            int hc = (v != vec[u].fi.fi) ? vec[u].fi.se : vec[u].se.se;
            int newUp = max(up,hc)+1;
            solve(v,u,newUp,h,adj,vec);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<pii> vec;
        for( int i = 0 ; i < n ; i++ )
            vec.pb(pii(pi(-1,-1),pi(-1,-1)));
        vector<vi> adj(n);
        for( int i = 0 ; i < n-1 ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> h(n);
        dfs(0,-1,h,adj,vec);
        solve(0,-1,0,h,adj,vec);
        return roots;
    }
};