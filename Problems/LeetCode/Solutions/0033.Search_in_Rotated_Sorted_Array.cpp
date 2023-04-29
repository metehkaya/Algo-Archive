class Solution {
public:
    int findIndex(vector<int>& ar, int& target, int l, int r) {
        while(l <= r) {
            int mid = (l+r)>>1;
            if(ar[mid] == target)
                return mid;
            else if(ar[mid] < target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    int search(vector<int>& ar, int target) {
        int n = ar.size();
        if(n == 0)
            return -1;
        int l=1,r=n-1,minIndex=0;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(ar[mid] > ar[0])
                l=mid+1;
            else
                minIndex=mid, r=mid-1;
        }
        int leftIndex = -1;
        int rightIndex = findIndex(ar, target, minIndex, n-1);
        if(minIndex > 0)
            leftIndex = findIndex(ar, target, 0, minIndex-1);
        if(leftIndex != -1)
            return leftIndex;
        if(rightIndex != -1)
            return rightIndex;
        return -1;
    }
};