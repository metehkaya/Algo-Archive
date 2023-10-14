class Solution {
public:
    static const int maxn = 30000;
    int ans,k;
    vector<int> values;
    vector<int> adj[maxn];
    int dfs(int u , int dad) {
        int sum = values[u] % k;
        for(int v : adj[u])
            if(v != dad)
                sum = (sum + dfs(v,u)) % k;
        if(sum == 0)
            ans++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        this->values = values;
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1);
        return ans;
    }
};
