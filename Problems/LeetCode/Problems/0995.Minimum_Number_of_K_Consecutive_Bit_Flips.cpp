class Solution {
public:
    int minKBitFlips(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0 , f = 0;
        vector<int> flip(n+1,0);
        for( int i = 0 ; i <= n-k ; i++ ) {
            f ^= flip[i];
            ar[i] ^= f;
            if(ar[i] == 0) {
                ans++;
                ar[i] = 1;
                flip[i+1] ^= 1;
                flip[i+k] ^= 1;
            }
        }
        for( int i = n-k+1 ; i < n ; i++ ) {
            f ^= flip[i];
            ar[i] ^= f;
            if(ar[i] == 0)
                return -1;
        }
        return ans;
    }
};