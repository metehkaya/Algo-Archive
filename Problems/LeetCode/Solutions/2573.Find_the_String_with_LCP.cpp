class Solution {
public:
    static const int maxn = 1000;
    int g;
    int group[maxn];
    bool mark[maxn][maxn];
    vector<int> adj[maxn];
    void dfs(int u) {
        group[u] = g;
        for(int v : adj[u])
            if(group[v] == -1)
                dfs(v);
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                if(lcp[i][j] != lcp[j][i])
                    return "";
                if(lcp[i][j]) {
                    mark[i][j] = true;
                    adj[i].push_back(j);
                    int exp = (i+1 == n or j+1 == n) ? 1 : lcp[i+1][j+1] + 1;
                    if(lcp[i][j] != exp)
                        return "";
                }
                if(i == j and lcp[i][j] != n-i)
                    return "";
            }
        memset(group,-1,sizeof(group));
        for( int i = 0 ; i < n ; i++ )
            if(group[i] == -1) {
                dfs(i);
                g++;
            }
        if(g > 26)
            return "";
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(group[i] == group[j] and (!mark[i][j] or !mark[j][i]))
                    return "";
        string ans = "";
        for( int i = 0 ; i < n ; i++ )
            ans.push_back('a'+group[i]);
        return ans;
    }
};
