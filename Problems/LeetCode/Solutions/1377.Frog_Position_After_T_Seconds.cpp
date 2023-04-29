typedef vector<int> vi;
typedef vector<vi> vii;

struct Result {
    int lvl;
    bool isLeaf;
    double p;
    Result( int _lvl , bool _isLeaf , double _p ) {
        lvl = _lvl;
        isLeaf = _isLeaf;
        p = _p;
    }
};

class Solution {
public:
    Result dfs( int u , int dad , int lvl , double p , int target , int t , vii& adj ) {
        int sz = adj[u].size();
        int nchild = sz - ( dad == -1 ? 0 : 1 );
        if(u == target) {
            bool isLeaf = (nchild == 0);
            return Result(lvl,isLeaf,p);
        }
        Result res(-1,-1,-1);
        for( int i = 0 ; i < sz ; i++ ) {
            int v = adj[u][i];
            if(v == dad)
                continue;
            res = dfs(v,u,lvl+1,p/nchild,target,t,adj);
            if(res.lvl != -1)
                return res;
        }
        return res;
    }
    double frogPosition(int n, vii& edges, int t, int target) {
        vii adj(n);
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Result res = dfs(0,-1,0,1.0,--target,t,adj);
        double ans = 0.0;
        if(res.isLeaf && res.lvl <= t)
            ans = res.p;
        else if(!res.isLeaf && res.lvl == t)
            ans = res.p;
        return ans;
    }
};