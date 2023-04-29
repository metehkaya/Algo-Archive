class Solution {
public:
    static const int maxn = 100000;
    int dad[maxn];
    int rank[maxn];
    int findPar(int u) {
        if(dad[u] == -1)
            return u;
        return dad[u] = findPar(dad[u]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = edges.size();
        int q = queries.size();
        sort(edges.begin() , edges.end() , [&](vector<int>& a , vector<int>& b) {
            return a[2] < b[2];
        });
        for( int i = 0 ; i < q ; i++ )
            queries[i].push_back(i);
        sort(queries.begin() , queries.end() , [&](vector<int>& a , vector<int>& b) {
            return a[2] < b[2];
        });
        memset(dad,-1,sizeof(dad));
        memset(rank,0,sizeof(rank));
        vector<bool> ans(q);
        for( int i = 0 , j = 0 ; i < m || j < q ;  ) {
            if(i == m || (j < q && i < m && queries[j][2] <= edges[i][2])) {
                int u = findPar(queries[j][0]);
                int v = findPar(queries[j][1]);
                ans[queries[j][3]] = (u == v);
                j++;
            }
            else {
                int u = findPar(edges[i][0]);
                int v = findPar(edges[i][1]);
                if(u != v) {
                    if(rank[u] < rank[v])
                        swap(u,v);
                    dad[v] = u;
                    rank[u] += (rank[u] == rank[v]);
                }
                i++;
            }
        }
        return ans;
    }
};