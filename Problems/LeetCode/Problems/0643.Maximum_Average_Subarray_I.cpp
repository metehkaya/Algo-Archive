class Solution {
public:
    double findMaxAverage(vector<int>& ar, int k) {
        int n = ar.size();
        int sum = 0 , maxSum = 0;
        for( int i = 0 ; i < k ; i++ )
            sum += ar[i];
        maxSum = sum;
        for( int i = k ; i < n ; i++ ) {
            sum += ar[i]-ar[i-k];
            maxSum = max(maxSum,sum);
        }
        return (double) maxSum/k;
    }
};