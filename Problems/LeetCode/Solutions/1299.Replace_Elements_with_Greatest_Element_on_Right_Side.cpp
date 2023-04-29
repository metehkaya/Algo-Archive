class Solution {
public:
    vector<int> replaceElements(vector<int>& ar) {
        int n = ar.size();
        int mx = -1;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int temp = ar[i];
            ar[i] = mx;
            mx = max( mx , temp );
        }
        return ar;
    }
};