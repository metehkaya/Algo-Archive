class Solution {
public:
    void moveZeroes(vector<int>& ar) {
        int n = ar.size();
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            if( ar[i] != 0 ) {
                swap( ar[i] , ar[cnt] );
                cnt++;
            }
    }
};