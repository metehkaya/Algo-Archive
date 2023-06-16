class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<bool> marked_vertex(n, false);
        for(int vertex : marked)
            marked_vertex[vertex] = true;
        vector<vector<int>> adj[n];
        for(auto e : edges)
            adj[e[0]].push_back({e[1],e[2]});
        vector<int> dist(n,INT_MAX);
        dist[s] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        heap.push({0,s});
        while(!heap.empty()) {
            vector<int> temp = heap.top();
            heap.pop();
            int u = temp[1] , d = temp[0];
            if(marked_vertex[u])
                return d;
            if(d > dist[u])
                continue;
            for(auto e : adj[u]) {
                int v = e[0] , d_v = d+e[1];
                if(d_v < dist[v]) {
                    dist[v] = d_v;
                    heap.push({d_v,v});
                }
            }
        }
        return -1;
    }
};
