class Solution {
public:
    int minimumDeletions(vector<int>& ar) {
        int n = ar.size() , mn = INT_MAX , mx = INT_MIN;
        int idx_mn , idx_mx;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] < mn) {
                mn = ar[i];
                idx_mn = i;
            }
            if(ar[i] > mx) {
                mx = ar[i];
                idx_mx = i;
            }
        }
        if(idx_mn > idx_mx)
            swap(idx_mn,idx_mx);
        int ans = max(idx_mn,n-1-idx_mx);
        ans = max(ans,idx_mx-idx_mn-1);
        return n-ans;
    }
};
