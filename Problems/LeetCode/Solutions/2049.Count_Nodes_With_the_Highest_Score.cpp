typedef long long LL;

class Solution {
public:
    int n;
    static const int maxn = 100003;
    int cnt[maxn];
    vector<int> adj[maxn];
    int dfs(int u) {
        cnt[u] = 1;
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            cnt[u] += dfs(adj[u][i]);
        return cnt[u];
    }
    LL getScore(int u) {
        LL mult = 1;
        if(u > 0)
            mult = n-cnt[u];
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            mult *= cnt[adj[u][i]];
        return mult;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        for( int i = 1 ; i < n ; i++ )
            adj[parents[i]].push_back(i);
        dfs(0);
        LL best = 0;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            LL score = getScore(i);
            if(score > best)
                best = score , ans = 1;
            else if(score == best)
                ans++;
        }
        return ans;
    }
};
