class Solution {
public:
    int singleNonDuplicate(vector<int>& ar) {
        int n = ar.size();
        int m = (n+1) / 2;
        int l=0 , r=m-1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int ind = mid * 2;
            if(ind+1 < n && ar[ind] == ar[ind+1])
                l = mid+1;
            else if(ind-1 >= 0 && ar[ind] == ar[ind-1])
                r = mid-1;
            else
                return ar[ind];
        }
        return -1;
    }
};