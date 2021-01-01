class Solution {
public:
    const double EPS = 1e-7;
    const double MAXS = 100000000;
    double minmaxGasDist(vector<int>& ar, int K) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        double l = 0 , r = MAXS , ans = MAXS;
        while(r-l > EPS) {
            int k = K;
            double val = (l+r)/2;
            for( int i = 1 ; i < n && k >= 0 ; i++ ) {
                double diff = ar[i]-ar[i-1];
                if(diff > val) {
                    int q = diff/val;
                    double p = q*val;
                    int req = q-(p==diff);
                    k -= req;
                }
            }
            if(k >= 0)
                ans = r = val;
            else
                l = val;
        }
        return ans;
    }
};