class LockingTree {
public:
    int n;
    int state[2000];
    vector<int> p;
    vector<int> adj[2000];
    int cntLockedAncestors;
    int cntLockedDescendants;
    vector<int> descendants;
    LockingTree(vector<int>& parent) {
        p = parent;
        n = p.size();
        for( int i = 1 ; i < n ; i++ )
            adj[p[i]].push_back(i);
        memset(state,0,sizeof(state));
    }
    bool lock(int num, int user) {
        bool res = !state[num];
        if(res)
            state[num] = user;
        return res;
    }
    bool unlock(int num, int user) {
        bool res = (state[num] == user);
        if(res)
            state[num] = 0;
        return res;
    }
    void dfs(int u , int root) {
        if(u != root) {
            descendants.push_back(u);
            cntLockedDescendants += (state[u] > 0);
        }
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(adj[u][i],root);
    }
    bool upgrade(int num, int user) {
        bool res = !state[num];
        if(res) {
            cntLockedAncestors = 0;
            int u = p[num];
            while(u != -1) {
                cntLockedAncestors += (state[u] > 0);
                u = p[u];
            }
            res = !cntLockedAncestors;
            if(res) {
                descendants.clear();
                cntLockedDescendants = 0;
                dfs(num,num);
                res = (cntLockedDescendants > 0);
            }
        }
        if(res) {
            state[num] = user;
            int sz = descendants.size();
            for( int i = 0 ; i < sz ; i++ )
                state[descendants[i]] = 0;
        }
        return res;
    }
};