class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1 , r = n*m , ans;
        while(l <= r) {
            int sum = 0;
            int x = (l+r) >> 1;
            for( int i = 1 ; i <= n ; i++ )
                sum += min(x/i,m);
            if(sum >= k)
                ans = x , r = x-1;
            else
                l = x+1;
        }
        return ans;
    }
};