class Solution {
public:
    static const int maxn = 100000;
    map<int,int> mp;
    bool mark[maxn];
    vector<int> adj[maxn];
    void dfs(int u , vector<int>& s, vector<int>& t) {
        mp[s[u]]++;
        mp[t[u]]--;
        mark[u] = true;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v,s,t);
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& edges) {
        int n = s.size();
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        memset(mark,false,sizeof(mark));
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                mp.clear();
                dfs(i,s,t);
                for(auto it : mp)
                    ans += max(it.second,0);
            }
        return ans;
    }
};