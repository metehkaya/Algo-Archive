class Solution {
public:
    int partitionDisjoint(vector<int>& ar) {
        int n = ar.size();
        vector<int> mn(n),mx(n);
        mn[n-1] = ar[n-1];
        for( int i = n-2 ; i >= 0 ; i-- )
            mn[i] = min( mn[i+1] , ar[i] );
        mx[0] = ar[0];
        if(mx[0] <= mn[1])
            return 1;
        for( int i = 1 ; i < n-1 ; i++ ) {
            mx[i] = max( mx[i-1] , ar[i] );
            if(mx[i] <= mn[i+1])
                return i+1;
        }
        return -1;
    }
};