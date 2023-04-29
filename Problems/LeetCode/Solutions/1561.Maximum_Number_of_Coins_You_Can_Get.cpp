class Solution {
public:
    int maxCoins(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        int n = ar.size()/3 , ans = 0;
        for( int i = 3*n-2 ; i >= n ; i -= 2 )
            ans += ar[i];
        return ans;
    }
};