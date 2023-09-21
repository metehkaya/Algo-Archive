class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> a,b;
        for( int i = 0 ; i < 3 ; i++ )
            for( int j = 0 ; j < 3 ; j++ )
                if(grid[i][j] == 0)
                    a.push_back({i,j});
                else
                    for( int val = 1 ; val < grid[i][j] ; val++ )
                        b.push_back({i,j});
        int sz = a.size() , ans = INT_MAX;
        vector<int> perm;
        for( int i = 0 ; i < sz ; i++ )
            perm.push_back(i);
        do {
            int sum = 0;
            for( int i = 0 ; i < sz ; i++ ) {
                int idx1x = a[i][0] , idx1y = a[i][1];
                int idx2x = b[perm[i]][0] , idx2y = b[perm[i]][1];
                sum += abs(idx1x-idx2x) + abs(idx1y-idx2y);
            }
            ans = min(ans,sum);
        }while(next_permutation(perm.begin(),perm.end()));
        return ans;
    }
};
