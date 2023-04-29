class Solution {
public:
    int numSpecial(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 1) {
                    int cnt = 0;
                    for( int k = 0 ; k < m ; k++ )
                        cnt += ar[i][k];
                    for( int k = 0 ; k < n ; k++ )
                        cnt += ar[k][j];
                    if(cnt == 2)
                        ans++;
                }
        return ans;
    }
};