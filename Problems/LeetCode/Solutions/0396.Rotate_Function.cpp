class Solution {
public:
    int maxRotateFunction(vector<int>& ar) {
        int n = ar.size() , sum = 0 , curr = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            curr += i*ar[i];
        }
        int ans = curr;
        for( int i = 1 ; i < n ; i++ ) {
            curr -= (sum-ar[i-1]);
            curr += (n-1) * ar[i-1];
            ans = max(ans,curr);
        }
        return ans;
    }
};
