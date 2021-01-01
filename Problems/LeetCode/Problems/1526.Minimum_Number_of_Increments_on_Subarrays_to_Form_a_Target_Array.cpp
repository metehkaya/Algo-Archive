class Solution {
public:
    int minNumberOperations(vector<int>& ar) {
        int n = ar.size() , ans = ar[0];
        for( int i = 1 ; i < n ; i++ )
            ans += max(ar[i]-ar[i-1],0);
        return ans;
    }
};