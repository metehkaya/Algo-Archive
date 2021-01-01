class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& ar) {
        int n = ar.size() , l = 0 , r = n-1;
        while(l < n-1 && ar[l] <= ar[l+1])
            l++;
        while(r > 0 && ar[r] >= ar[r-1])
            r--;
        if(r == 0)
            return 0;
        int L = 1 , R = n-1 , ans;
        while(L <= R) {
            int m = (L+R) >> 1;
            bool ok = false;
            for( int i = 0 ; i <= n-m && !ok ; i++ ) {
                int j = i+m-1;
                if(l >= i-1 && r <= j+1)
                    if(i == 0 || j == n-1 || (ar[i-1] <= ar[j+1]))
                        ok = true;
            }
            if(ok) {
                ans = m;
                R = m-1;
            }
            else
                L = m+1;
        }
        return ans;
    }
};