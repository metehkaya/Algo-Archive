typedef vector<int> vi;
typedef vector<vi> vvi;

struct st {
    int sum,sz,res;
    st(int sum, int sz, int res) {
        this->sum = sum;
        this->sz = sz;
        this->res = res;
    }
};

class Solution {
public:
    st dfs(int u, vvi& adj, vi& value) {
        st ans(value[u], 1, 0);
        for( int i = 0 ; i < adj[u].size() ; i++ ) {
            int v = adj[u][i];
            st temp = dfs(v, adj, value);
            ans.sum += temp.sum;
            ans.sz += temp.sz;
            ans.res += temp.res;
        }
        if(ans.sum == 0)
            ans.res = ans.sz;
        return ans;
    }
    int deleteTreeNodes(int n, vi& parent, vi& value) {
        vvi adj(n);
        for( int i = 1 ; i < n ; i++ )
            adj[parent[i]].push_back(i);
        st ans = dfs(0,adj,value);
        return n - ans.res;
    }
};