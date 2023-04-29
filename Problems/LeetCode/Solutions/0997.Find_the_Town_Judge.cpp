class Solution {
public:
    int findJudge(int n, vector<vector<int>>& G) {
        vector<int> indeg(n,0);
        vector<int> outdeg(n,0);
        for( int i = 0 ; i < G.size() ; i++ ) {
            int u = G[i][0] - 1;
            int v = G[i][1] - 1;
            indeg[v]++;
            outdeg[u]++;
        }
        for( int i = 0 ; i < n ; i++ )
            if( indeg[i] == n-1 && outdeg[i] == 0 )
                return i+1;
        return -1;
    }
};