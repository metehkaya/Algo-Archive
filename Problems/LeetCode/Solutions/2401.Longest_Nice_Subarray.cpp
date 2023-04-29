class Solution {
public:
    int longestNiceSubarray(vector<int>& ar) {
        int n = ar.size() , ans = 0 , bmask = 0;
        for( int l = 0 , r = 0 ; l < n ; l++ ) {
            while(r < n && (bmask & ar[r]) == 0)
                bmask |= ar[r++];
            ans = max(ans,r-l);
            bmask ^= ar[l];
        }
        return ans;
    }
};
