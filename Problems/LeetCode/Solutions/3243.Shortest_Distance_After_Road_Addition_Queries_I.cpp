class Solution {
public:
    int solve(int n, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> dist(n,-1);
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u])
                if(dist[v] == -1) {
                    q.push(v);
                    dist[v] = dist[u]+1;
                }
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < n-1 ; i++ )
            adj[i].push_back(i+1);
        vector<int> ans;
        for(auto q : queries) {
            adj[q[0]].push_back(q[1]);
            ans.push_back(solve(n, adj));
        }
        return ans;
    }
};