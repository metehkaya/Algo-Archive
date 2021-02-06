class Solution {
public:
    int maxAbsoluteSum(vector<int>& ar) {
        int n = ar.size();
        int ans = 0 , sum = 0 , mn = 0 , mx = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            ans = max(ans,abs(sum-mn));
            ans = max(ans,abs(sum-mx));
            mn = min(mn,sum);
            mx = max(mx,sum);
        }
        return ans;
    }
};