#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<int,LL> piL;

struct cmp {
    bool operator()(piL& a , piL& b){
        return a.se > b.se;
    }
};

class Solution {
public:
    const int mod = (int) 1e9+7;
    int ans[200];
    LL dist[200];
    vector<pi> adj[200];
    priority_queue<piL,vector<piL>,cmp> heap;
    int countPaths(int n, vector<vector<int>>& ar) {
        int m = ar.size();
        for( int i = 0 ; i < m ; i++ ) {
            adj[ar[i][0]].pb(pi(ar[i][1],ar[i][2]));
            adj[ar[i][1]].pb(pi(ar[i][0],ar[i][2]));
        }
        memset(ans,0,sizeof(ans));
        ans[0] = 1;
        memset(dist,-1,sizeof(dist));
        dist[0] = 0;
        heap.push(piL(0,0));
        while(!heap.empty()) {
            piL p = heap.top();
            heap.pop();
            int u = p.fi;
            LL d = p.se;
            if(d > dist[u])
                continue;
            int deg = (int) adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i].fi;
                int way = adj[u][i].se;
                LL path = d+way;
                if(dist[v] == -1 || path < dist[v]) {
                    dist[v] = path;
                    ans[v] = ans[u];
                    heap.push(piL(v,path));
                }
                else if(dist[v] == path)
                    ans[v] = (ans[v] + ans[u]) % mod;
            }
        }
        return ans[n-1];
    }
};