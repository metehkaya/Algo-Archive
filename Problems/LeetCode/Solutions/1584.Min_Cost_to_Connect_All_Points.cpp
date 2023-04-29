#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pii> vpii;

class Solution {
public:
    int minCostConnectPoints(vii& ar) {
        int n = ar.size();
        int ans = 0;
        vi dad(n,-1);
        vi sz(n,1);
        vpii edges;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                edges.pb(pii( abs(ar[i][0]-ar[j][0]) + abs(ar[i][1]-ar[j][1]) , pi(i,j) ));
        sort(edges.begin(),edges.end());
        for( int i = 0 , cnt = 1 ; i < edges.size() && cnt < n ; i++ ) {
            int u = edges[i].se.fi;
            int v = edges[i].se.se;
            while(dad[u] != -1)
                u = dad[u];
            while(dad[v] != -1)
                v = dad[v];
            if(u == v)
                continue;
            cnt++;
            ans += edges[i].fi;
            if(sz[u] < sz[v]) {
                dad[u] = v;
                sz[v] += sz[u];
            }
            else {
                dad[v] = u;
                sz[u] = sz[v];
            }
        }
        return ans;
    }
};