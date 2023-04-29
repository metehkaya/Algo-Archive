class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        bool mark[n];
        memset(mark,false,sizeof(mark));
        queue<int> Q;
        Q.push(0);
        mark[0] = true;
        int cnt = 0;
        while(!Q.empty()) {
            cnt++;
            int u = Q.front();
            Q.pop();
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(!mark[v]) {
                    Q.push(v);
                    mark[v] = true;
                }
            }
        }
        return (cnt == n);
    }
};