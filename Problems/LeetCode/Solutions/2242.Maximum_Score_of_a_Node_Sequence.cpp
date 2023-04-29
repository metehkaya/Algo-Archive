#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int maximumScore(vector<int>& ar, vector<vector<int>>& edges) {
        int n = ar.size();
        int m = edges.size();
        vector<pi> best[n];
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            best[u].pb(pi(ar[v],v));
            best[v].pb(pi(ar[u],u));
        }
        for( int i = 0 ; i < n ; i++ )
            sort(best[i].begin(),best[i].end());
        int ans = -1;
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int szu = best[u].size();
            int szv = best[v].size();
            int idxu = max(szu-3,0);
            int idxv = max(szv-3,0);
            for( int a = idxu ; a < szu ; a++ )
                for( int b = idxv ; b < szv ; b++ ) {
                    int x = best[u][a].se;
                    int y = best[v][b].se;
                    int score = ar[u] + ar[v] + ar[x] + ar[y];
                    if(x != v && y != u && x != y)
                        ans = max(ans,score);
                }
        }
        return ans;
    }
};
