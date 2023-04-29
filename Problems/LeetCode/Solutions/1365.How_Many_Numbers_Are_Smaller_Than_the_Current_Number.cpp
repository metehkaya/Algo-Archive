class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans(n,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                ans[i] += ar[i]>ar[j];
        return ans;
    }
};