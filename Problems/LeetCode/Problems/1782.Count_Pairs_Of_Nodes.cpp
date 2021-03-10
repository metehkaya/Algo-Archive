#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int m = edges.size();
        vector<pi> deg;
        vector<int> idx(n);
        vector<int> Deg(n,0);
        for( int i = 0 ; i < n ; i++ )
            deg.pb(pi(0,i));
        map<int,int> cnt[n];
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            u-- , v--;
            Deg[u]++;
            Deg[v]++;
            deg[u].fi++;
            deg[v].fi++;
            cnt[u][v]++;
            cnt[v][u]++;
        }
        vector<int> ans;
        int Q = queries.size();
        sort(deg.begin(),deg.end());
        for( int i = 0 ; i < n ; i++ )
            idx[deg[i].se] = i;
        for( int q = 0 ; q < Q ; q++ ) {
            int res = 0;
            int lim = queries[q];
            for( int i = 0 , j = n ; i < n ; i++ ) {
                int u = deg[i].se;
                j = max(j,i+1);
                while(j-1 > i && deg[i].fi + deg[j-1].fi > lim)
                    j--;
                res += n-j;
                for(auto it : cnt[u]) {
                    int v = it.fi;
                    int w = it.se;
                    if(idx[v] >= j && Deg[u] + Deg[v] - w <= lim)
                        res--;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};