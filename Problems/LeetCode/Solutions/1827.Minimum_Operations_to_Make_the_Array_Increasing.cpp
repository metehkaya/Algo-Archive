class Solution {
public:
    int minOperations(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 1 ; i < n ; i++ ) {
            int val = max(ar[i],ar[i-1]+1);
            ans += val - ar[i];
            ar[i] = val;
        }
        return ans;
    }
};