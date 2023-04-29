class Solution {
public:
    int peakIndexInMountainArray(vector<int>& ar) {
        int n = ar.size();
        int l=1,r=n-2;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(ar[mid] > ar[mid-1] && ar[mid] > ar[mid+1])
                return mid;
            else if(ar[mid] < ar[mid+1])
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};