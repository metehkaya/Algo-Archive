class Solution {
public:
    bool search(vector<int>& ar, int target) {
        int n = ar.size();
        int l = 0 , r = n-1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(ar[mid] == target)
                return true;
            if(ar[l] == ar[mid]) {
                l++;
                continue;
            }
            bool isMidLeft = (ar[mid] >= ar[l]);
            bool isTargetLeft = (target >= ar[l]);
            if(isMidLeft == isTargetLeft) {
                if(ar[mid] < target)
                    l = mid+1;
                else
                    r = mid-1;
            }
            else {
                if(isMidLeft)
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return false;
    }
};