class Solution {
public:
    vector<int> singleNumber(vector<int>& ar) {
        int n = ar.size();
        int allXor = 0;
        for( int i = 0 ; i < n ; i++ )
            allXor ^= ar[i];
        int bitVal = -1;
        for( int i = 0 ; i < 32 ; i++ )
            if(allXor & (1<<i)) {
                bitVal = (1<<i);
                break;
            }
        vector<int> ans(2,0);
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] & bitVal)
                ans[0] ^= ar[i];
            else
                ans[1] ^= ar[i];
        return ans;
    }
};