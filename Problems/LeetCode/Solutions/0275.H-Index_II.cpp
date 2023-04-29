class Solution {
public:
    int hIndex(vector<int>& ar) {
        int n = ar.size();
        int ans = 0 , l = 0 , r = n-1;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(ar[m] >= n-m)
                ans = n-m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};