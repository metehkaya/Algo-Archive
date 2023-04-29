class Solution {
public:
    static const int maxn = (int) 1e3;
    int ans = INT_MAX;
    vector<int> adj[maxn];
    void bfs(int src , int dest) {
        queue<int> q;
        vector<int> dist(maxn,-1);
        q.push(src);
        dist[src] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                if((src == u and dest == v) or (src == v and dest == u))
                    continue;
                if(dist[v] != -1)
                    continue;
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
        if(dist[dest] != -1)
            ans = min(ans,dist[dest]+1);
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto e : edges)
            bfs(e[0],e[1]);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
