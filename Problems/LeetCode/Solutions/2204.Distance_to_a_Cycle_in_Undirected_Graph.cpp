class Solution {
public:
    static const int maxn = (int) 1e5;
    int head = -1 , tail = -1;
    int par[maxn];
    bool mark[maxn];
    vector<int> adj[maxn];
    void dfs(int u , int dad) {
        par[u] = dad;
        mark[u] = true;
        for(int v : adj[u])
            if(v != dad) {
                if(mark[v]) {
                    head = u;
                    tail = v;
                }
                else
                    dfs(v,u);
            }
    }
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        memset(mark,false,sizeof(mark));
        dfs(0,-1);
        queue<int> q;
        vector<int> ans(n,-1);
        for( int u = tail ; u != head ; u = par[u] ) {
            q.push(u);
            ans[u] = 0;
        }
        q.push(head);
        ans[head] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u])
                if(ans[v] == -1) {
                    ans[v] = ans[u]+1;
                    q.push(v);
                }
        }
        return ans;
    }
};
