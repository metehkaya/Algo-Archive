class Solution {
public:
    int smallestRangeII(vector<int>& ar, int k) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int ans = ar[n-1] - ar[0];
        for( int i = 0 ; i < n-1 ; i++ ) {
            int diff = max(ar[i]-ar[0],ar[n-1]-ar[i+1]);
            diff = max(diff,abs(ar[n-1]-ar[i]-2*k));
            diff = max(diff,abs(ar[n-1]-ar[0]-2*k));
            diff = max(diff,abs(ar[i+1]-ar[i]-2*k));
            diff = max(diff,abs(ar[i+1]-ar[0]-2*k));
            ans = min(ans,diff);
        }
        return ans;
    }
};