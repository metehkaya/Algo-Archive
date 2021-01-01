typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    void dfs( int u , int t , int& ans , vi& ar , vii& adj ) {
        t += ar[u];
        ans = max( ans , t );
        int sz = adj[u].size();
        for( int i = 0 ; i < sz ; i++ )
            dfs( adj[u][i] , t , ans , ar , adj );
    }
    int numOfMinutes(int n, int headID, vi& par, vi& ar) {
        vii adj(n);
        for( int i = 0 ; i < n ; i++ )
            if( par[i] != -1 )
                adj[par[i]].push_back(i);
        int ans = 0;
        dfs(headID,0,ans,ar,adj);
        return ans;
    }
};