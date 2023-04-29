class Solution {
public:
    vector<int> createTargetArray(vector<int>& ar, vector<int>& index) {
        int n = ar.size();
        vector<int> ans(n);
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = i ; j > index[i] ; j-- )
                ans[j] = ans[j-1];
            ans[index[i]] = ar[i];
        }
        return ans;
    }
};