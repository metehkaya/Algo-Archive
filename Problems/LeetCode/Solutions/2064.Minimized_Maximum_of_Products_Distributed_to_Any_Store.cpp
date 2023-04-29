typedef long long LL;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& ar) {
        int l = 1 , r = 1e5 , m = ar.size() , ans = INT_MAX;
        while(l <= r) {
            LL cnt = 0;
            int mid = (l+r) >> 1;
            for( int i = 0 ; i < m ; i++ )
                cnt += ar[i]/mid + ((ar[i]%mid) > 0);
            if(cnt <= n)
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};
