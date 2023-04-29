class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int cnt0 = 0;
        for( int i = 0 ; i < n ; i++ )
            if( arr[i] == 0 )
                cnt0++;
        arr.resize(n+cnt0);
        for( int i = n+cnt0-1 ; i >= 0 ; i-- ) {
            if( arr[i-cnt0] != 0 )
                arr[i] = arr[i-cnt0];
            else {
                arr[i] = arr[i-1] = arr[i-cnt0];
                cnt0--;
                i--;
            }
        }
        arr.resize(n);
    }
};