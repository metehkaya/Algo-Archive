class Solution {
public:
    int minSwapsCouples(vector<int>& ar) {
        int n = ar.size();
        vector<int> pos(n,-1);
        for( int i = 0 ; i < n ; i++ )
            pos[ar[i]] = i;
        int ans = 0;
        for( int i = 0 ; i < n ; i += 2 )
            if( (ar[i] ^ ar[i+1]) != 1 ) {
                int& idx1 = pos[ar[i]^1];
                int& idx2 = pos[ar[i+1]];
                idx2 = idx1;
                idx1 = i+1;
                swap(ar[idx1],ar[idx2]);
                ans++;
            }
        return ans;
    }
};