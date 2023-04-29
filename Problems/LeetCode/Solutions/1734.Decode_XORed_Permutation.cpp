class Solution {
public:
    vector<int> decode(vector<int>& ar) {
        int n = ar.size()+1;
        vector<int> ans(n);
        ans[n-1] = (n%4 == 1) ? 1 : 0;
        for( int i = 0 ; i < n-1 ; i += 2 )
            ans[n-1] ^= ar[i];
        for( int i = n-2 ; i >= 0 ; i-- )
            ans[i] = ans[i+1] ^ ar[i];
        return ans;
    }
};