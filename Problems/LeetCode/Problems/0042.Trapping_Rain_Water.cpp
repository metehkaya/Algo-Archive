class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> mxLeft;
        int mx = 0;
        for( int i = 0 ; i < n ; i++ ) {
            mx = max(mx, arr[i]);
            mxLeft.push_back(mx);
        }
        mx = 0;
        int ans = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            mx = max(mx, arr[i]);
            int mx2 = min(mx, mxLeft[i]);
            ans += max(mx2-arr[i], 0);
        }
        return ans;
    }
};