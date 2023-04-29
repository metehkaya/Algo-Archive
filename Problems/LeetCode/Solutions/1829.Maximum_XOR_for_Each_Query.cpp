class Solution {
public:
    vector<int> getMaximumXor(vector<int>& ar, int b) {
        int n = ar.size();
        int B = (1<<b)-1;
        int bmask = 0;
        for( int i = 0 ; i < n ; i++ )
            bmask ^= ar[i];
        vector<int> ans;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans.push_back(bmask^B);
            bmask ^= ar[i];
        }
        return ans;
    }
};