typedef long long LL;

class Solution {
public:
    int findDuplicate(vector<int>& ar) {
        int n = ar.size();
        int l=1 , r=n-1 , ans=0;
        while(l <= r) {
            int m = (l+r) >> 1;
            int cnt = 0;
            for( int i = 0 ; i < n ; i++ )
                cnt += (ar[i] <= m);
            if(cnt > m)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};