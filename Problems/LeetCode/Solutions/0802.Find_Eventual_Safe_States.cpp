#define pb push_back

class Solution {
public:
    static const int maxn = 10000;
    int n;
    bool mark[maxn];
    bool cycle[maxn];
    stack<int> st;
    vector<int> comp;
    vector<int> adj[maxn];
    vector<int> adjrev[maxn];
    void dfs1(int u) {
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs1(v);
        }
        st.push(u);
    }
    void dfs2(int u) {
        comp.pb(u);
        mark[u] = true;
        int deg = adjrev[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adjrev[u][i];
            if(!mark[v])
                dfs2(v);
        }
    }
    void dfs3(int u) {
        mark[u] = cycle[u] = true;
        int deg = adjrev[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adjrev[u][i];
            if(!mark[v])
                dfs3(v);
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < graph[i].size() ; j++ ) {
                if(i == graph[i][j])
                    cycle[i] = true;
                adj[i].pb(graph[i][j]);
                adjrev[graph[i][j]].pb(i);
            }
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                dfs1(i);
        memset(mark,false,sizeof(mark));
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            comp.clear();
            if(!mark[u])
                dfs2(u);
            if(comp.size() > 1)
                for( int i = 0 ; i < comp.size() ; i++ )
                    cycle[comp[i]] = true;
        }
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i] && cycle[i])
                dfs3(i);
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            if(!cycle[i])
                ans.pb(i);
        return ans;
    }
};