#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    static const int maxn = 1000;
    int n,m,maxTime,ans;
    int cnt[maxn];
    vector<int> values;
    vector<pi> adj[maxn];
    void dfs(int u , int t , int s) {
        if(cnt[u]++ == 0)
            s += values[u];
        if(u == 0)
            ans = max(ans,s);
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i].fi;
            int t2 = adj[u][i].se;
            if(t+t2 <= maxTime)
                dfs(v,t+t2,s);
        }
        if(--cnt[u] == 0)
            s -= values[u];
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        n = values.size();
        m = edges.size();
        this->maxTime = maxTime;
        this->values = values;
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];
            adj[u].pb(pi(v,t));
            adj[v].pb(pi(u,t));
        }
        dfs(0,0,0);
        return ans;
    }
};
