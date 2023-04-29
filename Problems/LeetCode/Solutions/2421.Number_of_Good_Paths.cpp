class Solution {
public:
    static const int maxn = 30001;
    static const int maxv = 100001;
    vector<int> adj[maxn];
    vector<int> nodes[maxv];
    bool mark[maxn];
    int dad[maxn];
    int rank[maxn];
    int find(int u) {
        if(dad[u] == -1)
            return u;
        return dad[u] = find(dad[u]);
    }
    void add(int u , int v) {
        u = find(u);
        v = find(v);
        if(u == v)
            return;
        if(rank[u] > rank[v])
            swap(u,v);
        if(rank[u] == rank[v])
            rank[v]++;
        dad[u] = v;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size() , ans = 0;
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for( int i = 0 ; i < n ; i++ )
            nodes[vals[i]].push_back(i);
        memset(dad,-1,sizeof(dad));
        memset(mark,false,sizeof(mark));
        memset(rank,0,sizeof(rank));
        for( int val = 0 ; val < maxv ; val++ ) {
            for(int u : nodes[val])
                mark[u] = true;
            for(int u : nodes[val])
                for(int v : adj[u])
                    if(mark[v])
                        add(u,v);
            map<int,int> cnt;
            for(int u : nodes[val]) {
                int p = find(u);
                ans += ++cnt[p];
            }
        }
        return ans;
    }
};
