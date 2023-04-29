class Solution {
public:
    const double EPS = 1e-6;
    const double MAXS = 10000;
    double findMaxAverage(vector<int>& ar, int k) {
        int n = ar.size();
        vector<double> sum(n+1);
        double l = -MAXS , r = MAXS , ans = -MAXS;
        while(r-l > EPS) {
            double val = (l+r)/2;
            sum[0] = 0;
            double minVal = (double) INT_MAX;
            bool exists = false;
            for( int i = 1 ; i <= n ; i++ ) {
                sum[i] = sum[i-1] + (ar[i-1]-val);
                if(i >= k) {
                    minVal = min(minVal,sum[i-k]);
                    if(minVal <= sum[i]) {
                        exists = true;
                        break;
                    }
                }
            }
            if(exists)
                ans = val , l = val;
            else
                r = val;
        }
        return ans;
    }
};