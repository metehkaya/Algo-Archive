class Solution {
public:
    int firstMissingPositive(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            ar[i] = max(ar[i],0);
        for( int i = 0 ; i < n ; i++ ) {
            int x = abs(ar[i]);
            if(x >= 1 && x <= n) {
                if(ar[x-1] == 0)
                    ar[x-1] = -n-1;
                else if(ar[x-1] > 0)
                    ar[x-1] *= -1;
            }
        }
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] >= 0)
                return i+1;
        return n+1;
    }
};