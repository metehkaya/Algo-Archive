class Solution {
public:
    int getMax(int val) {
        return max(val,0);
    }
    int maximumSum(vector<int>& ar) {
        int n = ar.size() , mn;
        if(n == 1)
            return ar[0];
        mn = 0;
        vector<int> lmax(n);
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            lmax[i] = sum - mn;
            mn = min(mn , sum);
        }
        mn = 0;
        vector<int> rmax(n);
        for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
            sum += ar[i];
            rmax[i] = sum - mn;
            mn = min(mn , sum);
        }
        int ans = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            if(i == 0) {
                ans = max(ans , rmax[i+1] + getMax(ar[i]));
                ans = max(ans , getMax(rmax[i+1]) + ar[i]);
            }
            else if(i == n-1) {
                ans = max(ans , lmax[i-1] + getMax(ar[i]));
                ans = max(ans , getMax(lmax[i-1]) + ar[i]);
            }
            else {
                ans = max(ans , lmax[i-1] + getMax(ar[i]) + getMax(rmax[i+1]));
                ans = max(ans , getMax(lmax[i-1]) + ar[i] + getMax(rmax[i+1]));
                ans = max(ans , getMax(lmax[i-1]) + getMax(ar[i]) + rmax[i+1]);
            }
        }
        return ans;
    }
};