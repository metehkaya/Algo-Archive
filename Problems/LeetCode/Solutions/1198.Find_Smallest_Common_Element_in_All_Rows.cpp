class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        vector<int> ind(n,0);
        for( int j = 0 ; j < m ; j++ ) {
            for( int i = 1 ; i < n ; i++ )
                while(ind[i] < m && ar[i][ind[i]] < ar[0][j])
                    ind[i]++;
            bool ok = true;
            for( int i = 1 ; ok && i < n ; i++ )
                if(ind[i] == m || ar[i][ind[i]] > ar[0][j])
                    ok = false;
            if(ok)
                return ar[0][j];
        }
        return -1;
    }
};