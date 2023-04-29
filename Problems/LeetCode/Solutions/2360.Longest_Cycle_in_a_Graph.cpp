class Solution {
public:
    int n,ans=-1;
    vector<int> mark;
    vector<int> edges;
    void dfs(int u , int x) {
        mark[u] = x;
        if(edges[u] == -1) {
            mark[u] = -2;
            return;
        }
        int v = edges[u];
        if(mark[v] == -1)
            dfs(v,x+1);
        else if(mark[v] >= 0)
            ans = max(x-mark[v]+1,ans);
        mark[u] = -2;
    }
    int longestCycle(vector<int>& edges) {
        n = edges.size();
        this->edges = edges;
        mark.resize(n,-1);
        for( int i = 0 ; i < n ; i++ )
            if(mark[i] == -1)
                dfs(i,0);
        return ans;
    }
};
