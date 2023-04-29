class Solution {
public:
    int timeRequiredToBuy(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < k ; i++ )
            ans += min(ar[i],ar[k]);
        ans += ar[k];
        for( int i = k+1 ; i < n ; i++ )
            ans += min(ar[i],ar[k]-1);
        return ans;
    }
};
