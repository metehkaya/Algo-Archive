#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int n,m,root;
    int cnt[(1<<18)];
    vector<pi> qs[100000];
    vector<int> adj[100000];
    void update(int id , int val , int k , int add) {
        cnt[id] += add;
        if(k == -1)
            return;
        int way = ((val & (1<<k)) > 0);
        update(2*id+way,val,k-1,add);
    }
    int query(int id , int val , int k) {
        if(k == -1)
            return 0;
        int res = 0;
        int way = ((val & (1<<k)) > 0);
        if(cnt[2*id+!way])
            res = query(2*id+!way,val,k-1) + (1<<k);
        else
            res = query(2*id+way,val,k-1);
        return res;
    }
    void dfs(int u , vector<int>& ans) {
        update(1,u,16,+1);
        int sz = qs[u].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int val = qs[u][i].fi;
            int id = qs[u][i].se;
            int add = (val & (1<<17));
            ans[id] = query(1,val-add,16) + add;
        }
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(adj[u][i],ans);
        update(1,u,16,-1);
    }
    vector<int> maxGeneticDifference(vector<int>& p, vector<vector<int>>& q) {
        n = p.size();
        m = q.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(p[i] == -1)
                root = i;
            else
                adj[p[i]].push_back(i);
        }
        for( int i = 0 ; i < m ; i++ ) {
            int u = q[i][0];
            int val = q[i][1];
            qs[u].pb(pi(val,i));
        }
        vector<int> ans(m);
        dfs(root,ans);
        return ans;
    }
};