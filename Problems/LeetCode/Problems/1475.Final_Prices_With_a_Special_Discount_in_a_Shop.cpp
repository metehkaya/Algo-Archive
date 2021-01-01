class Solution {
public:
    vector<int> finalPrices(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans = ar;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(ar[j] <= ar[i]) {
                    ans[i] = ar[i] - ar[j];
                    break;
                }
        return ans;
    }
};