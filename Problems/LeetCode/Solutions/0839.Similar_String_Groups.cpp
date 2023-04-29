class Solution {
public:
    bool check(string& s , string& t) {
        int n = s.length() , diff = 0;
        for( int i = 0 ; i < n ; i++ )
            diff += (s[i] != t[i]);
        return diff <= 2;
    }
    void dfs(int u , vector<vector<int>>& adj , vector<bool>& mark) {
        mark[u] = true;
        for(int v : adj[u])
            if(!mark[v])
                dfs(v,adj,mark);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size() , ans = 0;
        vector<bool> mark(n,false);
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < i ; j++ )
                if(check(strs[i],strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                dfs(i,adj,mark);
                ans++;
            }
        return ans;
    }
};
