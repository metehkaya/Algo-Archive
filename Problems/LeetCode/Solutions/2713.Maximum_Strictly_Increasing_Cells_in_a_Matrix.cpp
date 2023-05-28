class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        vector<int> dp_row(n,0) , dp_col(m,0);
        map<int,vector<vector<int>>> mp;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                mp[v[i][j]].push_back({i,j});
        int ans = 0;
        for(auto it : mp) {
            vector<vector<int>>& indices = it.second;
            int k = indices.size();
            vector<int> scores;
            for( int i = 0 ; i < k ; i++ ) {
                int x = indices[i][0];
                int y = indices[i][1];
                scores.push_back(max(dp_row[x],dp_col[y])+1);
            }
            for( int i = 0 ; i < k ; i++ ) {
                int x = indices[i][0];
                int y = indices[i][1];
                dp_row[x] = max(dp_row[x],scores[i]);
                dp_col[y] = max(dp_col[y],scores[i]);
                ans = max(ans,scores[i]);
            }
        }
        return ans;
    }
};
