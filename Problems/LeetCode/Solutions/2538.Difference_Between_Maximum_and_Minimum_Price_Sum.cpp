#define fi first
#define se second
typedef long long LL;
typedef pair<LL, int> pi;
const int maxn = 100000;

class Solution {
public:
    LL ans=0;
    pi best[maxn][2];
    vector<int> adj[maxn];
    LL dfs(int u, int dad, vector<int>& price) {
        best[u][0] = best[u][1] = pi(-1,-1);
        for(int v : adj[u])
            if(v != dad) {
                LL c = dfs(v,u,price);
                if(c > best[u][0].fi) {
                    best[u][1] = best[u][0];
                    best[u][0] = pi(c,v);
                }
                else if(c > best[u][1].fi)
                    best[u][1] = pi(c,v);
            }
        return max(best[u][0].fi,0LL) + price[u];
    }
    void solve(int u, int dad, LL other, vector<int>& price) {
        LL chain = max(other,best[u][0].fi) + price[u];
        ans = max(ans,chain-price[u]);
        for(int v : adj[u])
            if(v != dad) {
                if(v == best[u][0].se) {
                    LL dist2 = max(other,best[u][1].fi) + price[u];
                    solve(v,u,dist2,price);
                }
                else {
                    LL dist2 = max(other,best[u][0].fi) + price[u];
                    solve(v,u,dist2,price);
                }
            }
    }
    LL maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,price);
        solve(0,-1,0,price);
        return ans;
    }
};
