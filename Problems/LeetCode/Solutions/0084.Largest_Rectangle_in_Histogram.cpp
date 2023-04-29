class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> S;
        int n = arr.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            while(!S.empty() && arr[i] < arr[S.top()]) {
                int val = arr[S.top()];
                S.pop();
                int index = S.empty() ? -1 : S.top();
                ans = max( ans , val * (i-1-index) );
            }
            S.push(i);
        }
        while(!S.empty()) {
            int val = arr[S.top()];
            S.pop();
            int index = S.empty() ? -1 : S.top();
            ans = max( ans , val * (n-1-index) );
        }
        return ans;
    }
};