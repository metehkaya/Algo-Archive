class Solution {
public:
    vector<int> rearrangeArray(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans(n);
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < (n+1)/2 ; i++ )
            ans[2*i] = ar[i];
        for( int i = 0 ; i < n/2 ; i++ )
            ans[2*i+1] = ar[n-1-i];
        return ans;
    }
};