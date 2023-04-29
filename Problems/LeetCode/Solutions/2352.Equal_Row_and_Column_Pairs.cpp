class Solution {
public:
    int equalPairs(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                bool ok = true;
                for( int k = 0 ; k < n && ok ; k++ )
                    if(ar[i][k] != ar[k][j])
                        ok = false;
                if(ok)
                    ans++;
            }
        return ans;
    }
};
