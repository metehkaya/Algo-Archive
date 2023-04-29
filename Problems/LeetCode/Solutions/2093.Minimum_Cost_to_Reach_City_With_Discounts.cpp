class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& edges, int discounts) {
        vector<vector<int>> adj[n];
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        int dist[n][discounts+1];
        memset(dist,-1,sizeof(dist));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        heap.push({0,0,discounts});
        dist[0][discounts] = 0;
        while(!heap.empty()) {
            auto vec = heap.top();
            heap.pop();
            int d = vec[0] , u = vec[1] , k = vec[2];
            if(d > dist[u][k])
                continue;
            if(u == n-1)
                return d;
            for(auto& e : adj[u]) {
                int v = e[0] , w = e[1];
                int d_new = d+w;
                if(dist[v][k] == -1 or d_new < dist[v][k]) {
                    dist[v][k] = d_new;
                    heap.push({d_new,v,k});
                }
                d_new = d+w/2;
                if(k > 0 and (dist[v][k-1] == -1 or d_new < dist[v][k-1])) {
                    dist[v][k-1] = d_new;
                    heap.push({d_new,v,k-1});
                }
            }
        }
        return -1;
    }
};
