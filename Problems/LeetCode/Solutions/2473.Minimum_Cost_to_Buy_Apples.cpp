class Solution {
public:
    int n;
    static const int maxn = 1000;
    int dist[maxn][maxn];
    vector<vector<int>> adj[maxn];
    void dijkstra(int src) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        dist[src][src] = 0;
        heap.push({0,src});
        while(!heap.empty()) {
            auto v = heap.top();
            heap.pop();
            int d = v[0] , u = v[1];
            if(d > dist[src][u])
                continue;
            for(auto e : adj[u]) {
                int v = e[0] , w = e[1];
                int d_v = d + w;
                if(dist[src][v] == -1 or d_v < dist[src][v]) {
                    dist[src][v] = d_v;
                    heap.push({d_v,v});
                }
            }
        }
    }
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        this->n = n;
        for(auto e : roads) {
            adj[e[0]-1].push_back({e[1]-1,e[2]});
            adj[e[1]-1].push_back({e[0]-1,e[2]});
        }
        memset(dist,-1,sizeof(dist));
        for( int i = 0 ; i < n ; i++ )
            dijkstra(i);
        vector<long long> ans;
        for( int i = 0 ; i < n ; i++ ) {
            int res = INT_MAX;
            for( int j = 0 ; j < n ; j++ )
                if(dist[i][j] != -1)
                    res = min(res,appleCost[j]+(k+1)*dist[i][j]);
            ans.push_back(res);
        }
        return ans;
    }
};
