class Solution {
public:
    int shipWithinDays(vector<int>& ar, int m) {
        int n = ar.size() , mx = 0 , total = 0;
        for( int i = 0 ; i < n ; i++ ) {
            total += ar[i];
            mx = max(mx,ar[i]);
        }
        int l = mx , r = total , ans = total;
        while(l <= r) {
            int sum = (l+r) >> 1 , cnt = 0;
            for( int i = 0 , j = 0 ; i < n ; i = j , cnt++ ) {
                int curr = 0;
                while(j < n && curr + ar[j] <= sum)
                    curr += ar[j++];
            }
            if(cnt <= m)
                ans = sum , r = sum-1;
            else
                l = sum+1;
        }
        return ans;
    }
};