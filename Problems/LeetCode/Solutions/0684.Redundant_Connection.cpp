class Solution {
public:
    static const int maxn = 1001;
    int n;
    int dad[maxn];
    int lvl[maxn];
    int findPar(int u) {
        if(!dad[u])
            return u;
        return dad[u] = findPar(dad[u]);
    }
    void merge(int u , int v) {
        if(lvl[u] > lvl[v])
            swap(u,v);
        dad[u] = v;
        if(lvl[u] == lvl[v])
            lvl[v]++;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> ans(2);
        for( int i = 0 ; i < n ; i++ ) {
            int u = findPar(edges[i][0]);
            int v = findPar(edges[i][1]);
            if(u == v) {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
                break;
            }
            merge(u,v);
        }
        return ans;
    }
};