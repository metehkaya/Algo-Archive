#define pb push_back

class Solution {
public:
    static const int maxn = 100003;
    int n,ans;
    vector<int> adj[maxn];
    int dfs(int u , string& s) {
        vector<int> cnt(2,0);
        for(int v : adj[u]) {
            int len = dfs(v,s);
            if(s[u] != s[v])
                cnt.pb(len);
        }
        sort(cnt.begin(),cnt.end(),std::greater<>());
        ans = max(ans,cnt[0]+cnt[1]+1);
        return cnt[0]+1;
    }
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        for( int i = 1 ; i < n ; i++ )
            adj[parent[i]].pb(i);
        dfs(0,s);
        return ans;
    }
};
