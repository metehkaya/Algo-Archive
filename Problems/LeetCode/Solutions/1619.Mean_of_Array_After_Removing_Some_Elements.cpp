class Solution {
public:
    double trimMean(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int x = n/20;
        int sum = 0;
        for( int i = x ; i < n-x ; i++ )
            sum += ar[i];
        return (double) sum / (n-2*x);
    }
};