class Solution {
public:
    int minStartValue(vector<int>& ar) {
        int n = ar.size();
        int mn = 0, sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            mn = min(mn, sum);
        }
        if(mn <= 0)
            return 1-mn;
        return 1;
    }
};