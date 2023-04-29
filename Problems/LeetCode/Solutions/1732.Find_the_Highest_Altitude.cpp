class Solution {
public:
    int largestAltitude(vector<int>& ar) {
        int n = ar.size();
        int sum = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};