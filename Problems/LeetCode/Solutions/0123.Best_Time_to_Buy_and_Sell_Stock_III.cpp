class Solution {
public:
    int maxProfit(vector<int>& ar) {
        int n = ar.size();
        vector<int> left(n+2,0);
        vector<int> right(n+2,0);
        int mn = INT_MAX;
        for( int i = 1 ; i <= n ; i++ ) {
            left[i] = left[i-1];
            if(ar[i-1] > mn)
                left[i] = max(left[i],ar[i-1]-mn);
            mn = min(mn,ar[i-1]);
        }
        int mx = INT_MIN;
        for( int i = n ; i >= 1 ; i-- ) {
            right[i] = right[i+1];
            if(ar[i-1] < mx)
                right[i] = max(right[i],mx-ar[i-1]);
            mx = max(mx,ar[i-1]);
        }
        int ans = left[n];
        for( int i = 2 ; i < n-1 ; i++ )
            ans = max( ans , left[i] + right[i+1] );
        return ans;
    }
};