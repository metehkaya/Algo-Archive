class Solution {
public:
    const int BIG = (int) 1e9;
    int minDays(vector<int>& ar, int m, int k) {
        int n = ar.size();
        int l = 1 , r = BIG , ans = -1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int adj = 0 , cnt = 0;
            for( int i = 0 ; i < n ; i++ ) {
                if(ar[i] <= mid)
                    adj++;
                else
                    adj = 0;
                if(adj == k)
                    adj = 0 , cnt++;
            }
            if(cnt >= m)
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};