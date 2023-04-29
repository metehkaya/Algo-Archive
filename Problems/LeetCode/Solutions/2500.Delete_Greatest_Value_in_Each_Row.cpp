class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            sort(ar[i].begin(),ar[i].end());
        int ans = 0;
        for( int j = 0 ; j < m ; j++ ) {
            int add = 0;
            for( int i = 0 ; i < n ; i++ )
                add = max(add,ar[i][j]);
            ans += add;
        }
        return ans;
    }
};
