typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    void dfs2(int u , vii& adj , vi& mark) {
        if(mark[u])
            return;
        mark[u] = 1;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            dfs2(adj[u][i],adj,mark);
    }
    void dfs(int u , vii& adj , vi& mark , stack<int>& st) {
        if(mark[u])
            return;
        mark[u] = 1;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(adj[u][i],adj,mark,st);
        st.push(u);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vii adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vi mark(n,0);
        stack<int> st;
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                dfs(i,adj,mark,st);
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            mark[i] = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(mark[u])
                continue;
            ans.push_back(u);
            dfs2(u,adj,mark);
        }
        return ans;
    }
};