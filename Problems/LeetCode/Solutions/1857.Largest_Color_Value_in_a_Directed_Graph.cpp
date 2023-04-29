class Solution {
public:
    static const int maxn = 100000;
    string s;
    bool mark[maxn];
    int cnt[maxn][26];
    vector<int> adj[maxn];
    void dfs(int u) {
        if(mark[u])
            return;
        mark[u] = true;
        int c = s[u]-'a';
        cnt[u][c] = 1;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            dfs(v);
            for( int j = 0 ; j < 26 ; j++ )
                cnt[u][j] = max(cnt[u][j],cnt[v][j]+(c==j));
        }
    }
    int largestPathValue(string s, vector<vector<int>>& edges) {
        this->s = s;
        int n = s.length();
        int m = edges.size();
        vector<int> indeg(n,0);
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            indeg[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<int> roots;
        for( int i = 0 ; i < n ; i++ )
            if(!indeg[i]) {
                q.push(i);
                roots.push_back(i);
            }
        int rem = n;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            rem--;
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(--indeg[v] == 0)
                    q.push(v);
            }
        }
        if(rem)
            return -1;
        int sz = roots.size();
        for( int i = 0 ; i < sz ; i++ )
            dfs(roots[i]);
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < 26 ; j++ )
                ans = max(ans,cnt[i][j]);
        return ans;
    }
};