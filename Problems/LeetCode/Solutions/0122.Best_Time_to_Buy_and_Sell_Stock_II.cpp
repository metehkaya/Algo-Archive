class Solution {
public:
    int maxProfit(vector<int>& ar) {
        int n = ar.size();
        int sum = 0;
        for( int i = 1 ; i < n ; i++ )
            sum += max( ar[i] - ar[i-1] , 0 );
        return sum;
    }
};