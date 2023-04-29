#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<LL,int> pi;

class Solution {
public:
    static const int maxn = 1e5;
    const LL inf = (1LL << 60);
    int n;
    LL dist[maxn][3];
    bool mark[maxn][3];
    vector<pi> adj[maxn][2];
    void dijkstra(int src , int type , int e) {
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        dist[src][type] = 0;
        heap.push(pi(0,src));
        while(!heap.empty()) {
            pi temp = heap.top();
            heap.pop();
            LL d = temp.fi;
            int u = temp.se;
            if(mark[u][type])
                continue;
            mark[u][type] = true;
            int deg = adj[u][e].size();
            for( int i = 0 ; i < deg ; i++ ) {
                LL w = adj[u][e][i].fi;
                int v = adj[u][e][i].se;
                if(!mark[v][type])
                    if(dist[v][type] == -1 || d+w < dist[v][type]) {
                        heap.push(pi(d+w,v));
                        dist[v][type] = d+w;
                    }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        this->n = n;
        for( int i = 0 ; i < edges.size() ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u][0].pb(pi(w,v));
            adj[v][1].pb(pi(w,u));
        }
        memset(dist,-1,sizeof(dist));
        memset(mark,false,sizeof(mark));
        dijkstra(src1,0,0);
        dijkstra(src2,1,0);
        dijkstra(dest,2,1);
        LL ans = inf;
        for( int i = 0 ; i < n ; i++ )
            if(mark[i][0] && mark[i][1] && mark[i][2])
                ans = min(ans,dist[i][0]+dist[i][1]+dist[i][2]);
        return (ans == inf) ? -1 : ans;
    }
};
