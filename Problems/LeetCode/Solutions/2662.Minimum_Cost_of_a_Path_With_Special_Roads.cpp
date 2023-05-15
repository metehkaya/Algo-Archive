class Solution {
public:
    vector<vector<int>> adj[402];
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& roads) {
        if(start == target)
            return 0;
        vector<vector<int>> v;
        map<vector<int>,int> mp;
        mp[start] = 0;
        mp[target] = 1;
        v.push_back(start);
        v.push_back(target);
        int n = 2;
        for(auto& road : roads) {
            int x1 = road[0] , y1 = road[1];
            int x2 = road[2] , y2 = road[3];
            int cost = road[4];
            if(mp.find({x1,y1}) == mp.end()) {
                mp[{x1,y1}] = n++;
                v.push_back({x1,y1});
            }
            if(mp.find({x2,y2}) == mp.end()) {
                mp[{x2,y2}] = n++;
                v.push_back({x2,y2});
            }
            int u = mp[{x1,y1}] , v = mp[{x2,y2}];
            adj[u].push_back({v,cost});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        heap.push({0,0});
        dist[0] = 0;
        while(!heap.empty()) {
            auto vec = heap.top();
            heap.pop();
            int d = vec[0] , u = vec[1];
            if(u == 1)
                return d;
            if(d > dist[u])
                continue;
            for( int i = 0 ; i < n ; i++ ) {
                int add = abs(v[u][0]-v[i][0]) + abs(v[u][1]-v[i][1]);
                int d_new = d+add;
                if(d_new < dist[i]) {
                    dist[i] = d_new;
                    heap.push({d_new,i});
                }
            }
            for(auto& edge : adj[u]) {
                int w = edge[0] , cost = edge[1];
                int d_new = d+cost;
                if(d_new < dist[w]) {
                    dist[w] = d_new;
                    heap.push({d_new,w});
                }
            }
        }
        return -1;
    }
};
