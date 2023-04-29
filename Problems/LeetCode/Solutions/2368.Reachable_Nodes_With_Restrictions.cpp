class Solution {
public:
    int ans;
    static const int maxn = 100000;
    vector<int> adj[maxn];
    bool isRestricted[maxn];
    void dfs(int u , int dad=-1) {
        if(isRestricted[u])
            return;
        ans++;
        for( int i = 0 ; i < adj[u].size() ; i++ )
            if(adj[u][i] != dad)
                dfs(adj[u][i],u);
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for( int i = 0 ; i < edges.size() ; i++ ) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for( int i = 0 ; i < restricted.size() ; i++ )
            isRestricted[restricted[i]] = true;
        dfs(0);
        return ans;
    }
};
