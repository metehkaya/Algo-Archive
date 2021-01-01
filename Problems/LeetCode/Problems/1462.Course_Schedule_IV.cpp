class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<bool>> G(n,vector<bool>(n,false));
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ )
            G[ edges[i][0] ][ edges[i][1] ] = true;
        for( int k = 0 ; k < n ; k++ )
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < n ; j++ )
                    G[i][j] = G[i][j] || ( G[i][k] && G[k][j] );
        vector<bool> ans;
        for( int i = 0 ; i < (int) q.size() ; i++ )
            ans.push_back( G[q[i][0]][q[i][1]] );
        return ans;
    }
};