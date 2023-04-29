class Solution {
public:
    double calculateTax(vector<vector<int>>& ar, int income) {
        double ans = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int lower = (i == 0) ? 0 : ar[i-1][0];
            if(income <= lower)
                break;
            int diff = min(income,ar[i][0])-lower;
            ans += diff * ar[i][1] / 100.0;
        }
        return ans;
    }
};
