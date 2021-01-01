class Solution {
public:
    int search(vector<int>& ar, int val) {
        int n = ar.size();
        int l = 0 , r = n-1;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(ar[m] == val)
                return m;
            else if(ar[m] < val)
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
};