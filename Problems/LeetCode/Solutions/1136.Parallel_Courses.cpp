typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& edges) {
        vii adj(n);
        vi indeg(n,0);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            indeg[v]++;
            adj[u].push_back(v);
        }
        queue<pi> Q;
        for( int i = 0 ; i < n ; i++ )
            if( indeg[i] == 0 )
                Q.push( pi(i,1) );
        int ans = -1 , visited = 0;
        while(!Q.empty()) {
            visited++;
            pi p = Q.front();
            int u = p.first;
            int d = p.second;
            ans = max( ans , d );
            Q.pop();
            int outdeg = adj[u].size();
            for( int i = 0 ; i < outdeg ; i++ ) {
                int v = adj[u][i];
                if( --indeg[v] == 0 )
                    Q.push( pi(v,d+1) );
            }
        }
        return visited < n ? -1 : ans;
    }
};