typedef long long LL;

class Solution {
public:
    static const int maxn = 100003;
    vector<int> adj[maxn];
    bool check_prime(int x) {
        if(x == 1)
            return false;
        int s = (int) sqrt(x);
        for( int i = 2 ; i <= s ; i++ )
            if(x % i == 0)
                return false;
        return true;
    }
    vector<int> dfs(int u , int dad , LL& ans) {
        vector<int> sum(2,0);
        bool is_prime = check_prime(u);
        sum[is_prime]++;
        for(int c : adj[u])
            if(c != dad) {
                vector<int> v = dfs(c,u,ans);
                ans += (LL) sum[1]*v[0] + (LL) sum[0]*v[1];
                if(is_prime)
                    sum[1] += v[0];
                else {
                    sum[0] += v[0];
                    sum[1] += v[1];
                }
            }
        return sum;
    }
    LL countPaths(int n, vector<vector<int>>& edges) {
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        LL ans = 0;
        dfs(1,0,ans);
        return ans;
    }
};
