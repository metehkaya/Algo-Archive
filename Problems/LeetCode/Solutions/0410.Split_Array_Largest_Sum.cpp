class Solution {
public:
    int splitArray(vector<int>& ar, int m) {
        int n = ar.size();
        int sum = 0;
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        int l = 0 , r = sum , ans = sum;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int cnt = 1;
            for( int i = 0 , total = 0 ; i < n ; i++ ) {
                if(ar[i] > mid) {
                    cnt = m+1;
                    break;
                }
                else if(total + ar[i] <= mid)
                    total += ar[i];
                else
                    total = ar[i] , cnt++;
            }
            if(cnt <= m)
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};