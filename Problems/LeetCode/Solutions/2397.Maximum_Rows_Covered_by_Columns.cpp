class Solution {
public:
    int maximumRows(vector<vector<int>>& ar, int cols) {
        int n = ar.size();
        int m = ar[0].size();
        int ans = 0;
        for( int bmask = 0 ; bmask < (1<<m) ; bmask++ ) {
            int c = 0;
            for( int i = 0 ; i < m ; i++ )
                if(bmask & (1<<i))
                    c++;
            if(c != cols)
                continue;
            int cnt = 0;
            for( int i = 0 ; i < n ; i++ ) {
                bool ok = true;
                for( int j = 0 ; j < m ; j++ )
                    if(ar[i][j] == 1 && (bmask & (1<<j)) == 0)
                        ok = false;
                cnt += ok;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
