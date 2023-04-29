class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        int m = edges.size();
        vector<int> adj[n];
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(0);
        vector<int> dist(n,-1);
        dist[0] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(dist[v] != -1)
                    continue;
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
        int ans = 0;
        for( int i = 1 ; i < n ; i++ ) {
            int d = 2*dist[i];
            int times = d / patience[i];
            int t = times * patience[i];
            if(t == d)
                t -= patience[i];
            ans = max(ans,t+d);
        }
        return ans+1;
    }
};
