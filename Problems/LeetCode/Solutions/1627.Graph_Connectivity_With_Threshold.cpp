class Solution {
public:
    static const int maxn = 10003;
    int dad[maxn];
    int lvl[maxn];
    int find(int u) {
        if(dad[u] == 0)
            return u;
        return dad[u] = find(dad[u]);
    }
    void f(int u , int v) {
        u = find(u);
        v = find(v);
        if(u == v)
            return;
        if(lvl[u] > lvl[v])
            swap(u,v);
        dad[u] = v;
        if(lvl[u] == lvl[v])
            lvl[v]++;
    }
    vector<bool> areConnected(int n, int t, vector<vector<int>>& q) {
        int m = q.size();
        for( int i = t+1 ; i <= n ; i++ )
            for( int j = i ; j <= n ; j += i )
                f(i,j);
        vector<bool> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int u = find(q[i][0]);
            int v = find(q[i][1]);
            ans.push_back(u==v);
        }
        return ans;
    }
};