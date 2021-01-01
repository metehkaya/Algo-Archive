class MountainArray {
public:
	int get(int index);
	int length();
};

class Solution {
public:
    int findBS(MountainArray &arr, int l, int r, int target, bool side) {
        if(l>r)
            return -1;
        int mid = (l+r)>>1;
        int val = arr.get(mid);
        if(val == target)
            return mid;
        else if(val < target) {
            if(!side)
                return findBS(arr,mid+1,r,target,side);
            return findBS(arr,l,mid-1,target,side);
        }
        if(!side)
            return findBS(arr,l,mid-1,target,side);
        return findBS(arr,mid+1,r,target,side);
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int l=0,r=n-2,mi;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int my = arr.get(mid);
            int next = arr.get(mid+1);
            if(my <= next) {
                mi = mid+1;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        int left = findBS(arr,0,mi,target,0);
        if(left != -1)
            return left;
        return findBS(arr,mi,n-1,target,1);
    }
};