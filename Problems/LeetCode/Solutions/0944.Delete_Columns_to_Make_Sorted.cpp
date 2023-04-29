class Solution {
public:
    int minDeletionSize(vector<string>& ar) {
        int n = ar.size() , m = ar[0].size() , ans = 0;
        for( int j = 0 ; j < m ; j++ ) {
            bool add = false;
            for( int i = 1 ; i < n ; i++ )
                if(ar[i][j] < ar[i-1][j])
                    add = true;
            ans += add;
        }
        return ans;
    }
};