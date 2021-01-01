class Solution {
public:
    void dfs(int u , string& s , vector<vector<int>>& adj , vector<bool>& mark , vector<int>& vi , vector<char>& vc) {
        mark[u] = true;
        vi.push_back(u);
        vc.push_back(s[u]);
        for( int i = 0 ; i < adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v,s,adj,mark,vi,vc);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& edges) {
        int n = s.length();
        string ans(n,'@');
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < edges.size() ; i++ ) {
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                vector<int> vi;
                vector<char> vc;
                dfs(i,s,adj,mark,vi,vc);
                sort(vi.begin(),vi.end());
                sort(vc.begin(),vc.end());
                for( int j = 0 ; j < vi.size() ; j++ )
                    ans[vi[j]] = vc[j];
            }
        return ans;
    }
};