#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    static const int maxn = 3000;
    int dist[maxn];
    vector<pi> adj[maxn];
    int reachableNodes(vector<vector<int>>& edges, int lim, int n) {
        int m = edges.size();
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].pb(pi(d,v));
            adj[v].pb(pi(d,u));
        }
        int ans = 0;
        heap.push(pi(0,0));
        memset(dist,-1,sizeof(dist));
        while(!heap.empty()) {
            pi temp = heap.top();
            heap.pop();
            int d = temp.fi;
            int u = temp.se;
            if(dist[u] != -1)
                continue;
            if(d <= lim)
                ans++;
            dist[u] = d;
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int c = adj[u][i].fi;
                int v = adj[u][i].se;
                if(dist[v] == -1)
                    heap.push(pi(d+c+1,v));
            }
        }
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            int a = 0 , b = 0;
            if(dist[u] != -1)
                a = max(lim-dist[u],0);
            if(dist[v] != -1)
                b = max(lim-dist[v],0);
            ans += min(a+b,d);
        }
        return ans;
    }
};