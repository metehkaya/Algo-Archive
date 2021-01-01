class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int mx = INT_MIN;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(mx != INT_MIN)
                ans = max( ans , mx-arr[i] );
            mx = max( mx , arr[i] );
        }
        return ans;
    }
};