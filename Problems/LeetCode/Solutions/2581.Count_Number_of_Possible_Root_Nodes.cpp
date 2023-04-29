class Solution {
public:
    static const int maxn = 100000;
    int n,k;
    vector<int> adj[maxn];
    set<int> guesses[maxn];
    int dfs1(int u , int dad) {
        int sum = 0;
        for(int v : adj[u])
            if(v != dad) {
                sum += dfs1(v,u);
                if(guesses[u].count(v))
                    sum++;
            }
        return sum;
    }
    int dfs2(int u , int dad , int cnt) {
        int ans = (cnt >= k);
        for(int v : adj[u])
            if(v != dad) {
                int cnt_new = cnt;
                if(guesses[u].count(v))
                    cnt_new--;
                if(guesses[v].count(u))
                    cnt_new++;
                ans += dfs2(v,u,cnt_new);
            }
        return ans;
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses_v, int k) {
        this->k = k;
        n = edges.size()+1;
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto v : guesses_v)
            guesses[v[0]].insert(v[1]);
        int sum = dfs1(0,-1);
        return dfs2(0,-1,sum);
    }
};
