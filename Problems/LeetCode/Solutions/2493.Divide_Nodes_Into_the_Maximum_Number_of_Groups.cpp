class Solution {
public:
    void dfs(int u, vector<bool>& mark, vector<int>& comp, vector<vector<int>>& adj) {
        mark[u] = true;
        comp.push_back(u);
        for(auto v : adj[u])
            if(!mark[v])
                dfs(v,mark,comp,adj);
    }
    int bfs(int u , vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> q;
        vector<int> dist(n,0);
        q.push(u);
        dist[u] = 1;
        int best = 0;
        while(!q.empty()) {
            u = q.front();
            q.pop();
            best = dist[u];
            for(int v : adj[u]) {
                if(dist[v] == 0) {
                    q.push(v);
                    dist[v] = dist[u]+1;
                }
                else if(dist[v] == dist[u])
                    return -1;
            }
        }
        return best;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        int ans = 0;
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                vector<int> comp;
                dfs(i,mark,comp,adj);
                int best = -1;
                for(int u : comp)
                    best = max(best,bfs(u,adj));
                if(best == -1)
                    return -1;
                ans += best;
            }
        return ans;
    }
};
