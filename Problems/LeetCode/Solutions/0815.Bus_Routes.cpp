#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    const int maxv = (int) 1e6;
    int numBusesToDestination(vector<vector<int>>& ar, int s, int t) {
        int n = ar.size();
        vector<int> dist(maxv+n,INT_MAX);
        vector<bool> mark(maxv+n,false);
        vector<vector<pi>> adj(maxv+n);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < ar[i].size() ; j++ ) {
                int u = ar[i][j];
                int v = maxv+i;
                adj[u].push_back(pi(v,1));
                adj[v].push_back(pi(u,0));
            }
        deque<int> q;
        q.push_front(s);
        dist[s] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop_front();
            if(u == t)
                return dist[u];
            if(mark[u])
                continue;
            mark[u] = true;
            int d = dist[u];
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i].fi;
                int c = adj[u][i].se;
                int d2 = d+c;
                if(d2 < dist[v]) {
                    dist[v] = d2;
                    if(c == 0)
                        q.push_front(v);
                    else
                        q.push_back(v);
                }
            }
        }
        return -1;
    }
};
