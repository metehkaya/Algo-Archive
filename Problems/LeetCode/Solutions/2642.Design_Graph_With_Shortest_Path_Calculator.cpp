struct st {
    bool operator()(const vector<int> &x , const vector<int> &y) {
        return x[1] > y[1];
    }
};

class Graph {
public:
    int n;
    vector<vector<int>> adj[100];
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(auto& e : edges)
            adj[e[0]].push_back({e[1],e[2]});
    }
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[1],e[2]});
    }
    int shortestPath(int src, int dest) {
        vector<int> dist(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,st> heap;
        dist[src] = 0;
        heap.push({src,0});
        while(!heap.empty()) {
            auto vec = heap.top();
            heap.pop();
            int u = vec[0] , d = vec[1];
            if(u == dest)
                return dist[u];
            if(d > dist[u])
                continue;
            for(auto& e : adj[u]) {
                int v = e[0] , w = e[1];
                int d2 = d + w;
                if(d2 < dist[v]) {
                    dist[v] = d2;
                    heap.push({v,d2});
                }
            }
        }
        return -1;
    }
};
