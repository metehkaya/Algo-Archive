class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans(n,1);
        if(n <= 1)
            return ans;
        for( int i = 1 ; i < n ; i++ )
            ans[i] = ans[i-1] * ar[i-1];
        int suffix = 1;
        for( int i = n-2 ; i >= 0 ; i-- ) {
            suffix *= ar[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }
};