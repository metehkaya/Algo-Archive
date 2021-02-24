class Solution {
public:
    int minimumSize(vector<int>& ar, int maxOp) {
        int n = ar.size();
        int l = 1 , r = (int)1e9 , ans = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            long long sum = 0;
            for( int i = 0 ; i < n ; i++ )
                if(m <= ar[i])
                    sum += ar[i]/m + (ar[i]%m>0) - 1;
            if(sum <= maxOp)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};