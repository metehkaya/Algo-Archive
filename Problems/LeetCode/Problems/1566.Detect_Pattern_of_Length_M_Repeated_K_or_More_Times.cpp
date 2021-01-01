class Solution {
public:
    bool containsPattern(vector<int>& ar, int m, int k) {
        int n = ar.size();
        for( int i = 0 ; i <= n-m*k ; i++ ) {
            bool ok = true;
            for( int j = 0 ; j < m*k ; j++ ) {
                int rem = j%m;
                if(ar[i+j] != ar[i+rem])
                    ok = false;
            }
            if(ok)
                return true;
        }
        return false;
    }
};