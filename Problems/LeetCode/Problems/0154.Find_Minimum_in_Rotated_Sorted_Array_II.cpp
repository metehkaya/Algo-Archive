class Solution {
public:
    int findMin(vector<int>& ar) {
        int n = ar.size();
        int l = 0 , r = n-1;
        while(l < r) {
            int m = (l+r) >> 1;
            if(ar[m] < ar[r])
                r = m;
            else if(ar[m] > ar[r])
                l = m+1;
            else
                r--;
        }
        return ar[l];
    }
};