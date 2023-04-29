class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v) {
        int n = v.size();
        vector<int> last(30,-1);
        vector<int> ans(n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans[i] = i;
            for( int j = 0 ; j < 30 ; j++ ) {
                if(v[i] & (1<<j))
                    last[j] = i;
                ans[i] = max(ans[i],last[j]);
            }
            ans[i] -= i-1;
        }
        return ans;
    }
};
