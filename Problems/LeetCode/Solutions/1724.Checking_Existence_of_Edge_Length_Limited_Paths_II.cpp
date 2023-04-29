class DistanceLimitedPathsExist {
public:
    vector<int> rank;
    vector<vector<int>> dad;
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        dad.resize(n,{-1,-1});
        sort(edges.begin() , edges.end() , [&](auto& e1 , auto& e2) {
            return e1[2] < e2[2];
        });
        for(auto e : edges) {
            int u = e[0] , v = e[1] , w = e[2];
            u = find_dad(u,INT_MAX);
            v = find_dad(v,INT_MAX);
            merge(u,v,w);
        }
    }
    int find_dad(int u, int limit) {
        while(dad[u][0] != -1 and dad[u][1] < limit)
            u = dad[u][0];
        return u;
    }
    void merge(int u, int v, int w) {
        if(u == v)
            return;
        if(rank[u] > rank[v])
            swap(u,v);
        dad[u] = {v,w};
        rank[v] = max(rank[v], rank[u]+1);
    }
    bool query(int u, int v, int limit) {
        u = find_dad(u,limit);
        v = find_dad(v,limit);
        return u == v;
    }
};
