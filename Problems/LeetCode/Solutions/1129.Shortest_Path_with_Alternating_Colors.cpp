typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& reds, vector<vector<int>>& blues) {
        queue<pi> Q;
        Q.push(pi(0,0));
        Q.push(pi(1,0));
        vii dist(2,vi(n,-1));
        dist[0][0] = dist[1][0] = 0;
        viii adj(2,vii(n));
        for( int i = 0 ; i < reds.size() ; i++ )
            adj[0][reds[i][0]].push_back(reds[i][1]);
        for( int i = 0 ; i < blues.size() ; i++ )
            adj[1][blues[i][0]].push_back(blues[i][1]);
        vi ans(n,-1);
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int k = temp.first;
            int u = temp.second;
            if(ans[u] == -1)
                ans[u] = dist[k][u];
            for( int i = 0 ; i < adj[k][u].size() ; i++ ) {
                int v = adj[k][u][i];
                if(dist[!k][v] == -1) {
                    Q.push(pi(!k,v));
                    dist[!k][v] = dist[k][u] + 1;
                }
            }
        }
        return ans;
    }
};