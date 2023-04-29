#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    static const int maxv = 51;
    static const int maxn = 100003;
    int n,m;
    vector<int> ans;
    vector<int> nums;
    stack<pi> st[maxv];
    vector<int> adj[maxn];
    bool valid[maxv][maxv];
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    void calcValid() {
        for( int i = 1 ; i < maxv ; i++ )
            for( int j = 1 ; j < maxv ; j++ )
                valid[i][j] = (gcd(i,j) == 1);
    }
    void dfs(int u , int dad , int lvl) {
        int best = -1;
        for( int i = 1 ; i < maxv ; i++ )
            if(valid[nums[u]][i] && !st[i].empty() && st[i].top().se > best)
                best = st[i].top().se , ans[u] = st[i].top().fi;
        st[nums[u]].push(pi(u,lvl));
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int to = adj[u][i];
            if(to != dad)
                dfs(to,u,lvl+1);
        }
        st[nums[u]].pop();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        m = edges.size();
        ans.resize(n,-1);
        this->nums = nums;
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        calcValid();
        dfs(0,-1,0);
        return ans;
    }
};