class Solution {
public:
    int maxSubArray(vector<int>& ar) {
        int ans=ar[0];
        int n = ar.size();
        for( int i = 0 , curr = 0 ; i < n ; i++ ) {
            curr += ar[i];
            ans = max(ans, curr);
            curr = max(curr, 0);
        }
        return ans;
    }
};