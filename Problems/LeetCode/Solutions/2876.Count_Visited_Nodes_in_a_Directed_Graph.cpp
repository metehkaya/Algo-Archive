class Solution {
public:
    void fill_cycle(int u, vector<int>& edges, vector<int>& cycle) {
        cycle.push_back(u);
        int v = edges[u];
        while(v != u) {
            cycle.push_back(v);
            v = edges[v];
        }
    }
    void dfs(int u, vector<int>& edges, vector<int>& mark, vector<int>& ans, vector<int>& cycle) {
        mark[u] = 1;
        int v = edges[u];
        if(!mark[v])
            dfs(v,edges,mark,ans,cycle);
        else if(mark[v] == 1)
            fill_cycle(v,edges,cycle);
        mark[u] = 2;
        ans[u] = ans[v]+1;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n,0) , mark(n,0);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                vector<int> cycle;
                dfs(i,edges,mark,ans,cycle);
                if(!cycle.empty()) {
                    int sz = cycle.size();
                    for(int u : cycle)
                        ans[u] = sz;
                }
            }
        return ans;
    }
};
