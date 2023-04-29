class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& ar, vector<int>& target) {
        int n = ar.size();
        vector<int> mx(3,0);
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = true;
            for( int j = 0 ; j < 3 ; j++ )
                if(target[j] < ar[i][j])
                    ok = false;
            if(ok)
                for( int j = 0 ; j < 3 ; j++ )
                    mx[j] = max(mx[j],ar[i][j]);
        }
        for( int i = 0 ; i < 3 ; i++ )
            if(mx[i] != target[i])
                return false;
        return true;
    }
};