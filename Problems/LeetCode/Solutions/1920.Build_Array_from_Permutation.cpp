class Solution {
public:
    vector<int> buildArray(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans(n);
        for( int i = 0 ; i < n ; i++ )
            ans[i] = ar[ar[i]];
        return ans;
    }
};