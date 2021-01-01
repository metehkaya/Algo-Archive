class Solution {
public:
    int missingNumber(vector<int>& ar) {
        int n = ar.size();
        int sum = 0;
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        return n*(n+1)/2 - sum;
    }
};