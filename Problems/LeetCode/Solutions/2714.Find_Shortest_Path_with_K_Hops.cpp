class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int f, int k) {
        vector<vector<int>> adj[n];
        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        dist[s][0] = 0;
        heap.push({0,s,0});
        while(!heap.empty()) {
            auto v = heap.top();
            heap.pop();
            int d = v[0] , u = v[1] , cnt = v[2];
            if(u == f)
                return d;
            if(d > dist[u][cnt])
                continue;
            for(auto& e : adj[u]) {
                int w = e[0] , d2 = d+e[1];
                if(d2 < dist[w][cnt]) {
                    dist[w][cnt] = d2;
                    heap.push({d2,w,cnt});
                }
                if(cnt < k and d < dist[w][cnt+1]) {
                    dist[w][cnt+1] = d;
                    heap.push({d,w,cnt+1});
                }
            }
        }
        return -1;
    }
};
