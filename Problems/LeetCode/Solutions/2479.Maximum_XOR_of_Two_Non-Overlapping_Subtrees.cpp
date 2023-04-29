typedef long long LL;

class Node {
public:
    Node* child[2];
    Node() {
        child[0] = child[1] = NULL;
    }
};

class Solution {
public:
    const int maxk = 60;
    static const int maxn = 50000;
    LL ans=0;
    LL sum[maxn];
    vector<int> adj[maxn];
    Node* root;
    void query(LL val) {
        if(root->child[0] == NULL and root->child[1] == NULL)
            return;
        LL res = 0;
        Node* node = root;
        int k = maxk-1;
        while(k >= 0) {
            int way = !!(val & (1LL<<k));
            if(node->child[!way]) {
                res |= (1LL<<k);
                node = node->child[!way];
            }
            else
                node = node->child[way];
            k--;
        }
        ans = max(ans,res);
    }
    void update(LL val) {
        Node* node = root;
        for( int k = maxk-1 ; k >= 0 ; k-- ) {
            int way = !!(val & (1LL<<k));
            if(node->child[way] == NULL)
                node->child[way] = new Node();
            node = node->child[way];
        }
    }
    void solve(int u , int dad) {
        query(sum[u]);
        for(int v : adj[u])
            if(v != dad)
                solve(v,u);
        update(sum[u]);
    }
    LL dfs(int u , int dad , vector<int>& val) {
        sum[u] = val[u];
        for(int v : adj[u])
            if(v != dad)
                sum[u] += dfs(v,u,val);
        return sum[u];
    }
    LL maxXor(int n, vector<vector<int>>& edges, vector<int>& val) {
        root = new Node();
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,val);
        solve(0,-1);
        return ans;
    }
};
