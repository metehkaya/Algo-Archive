class Solution {
public:
    int findMin(vector<int>& ar) {
        int ans = ar[0];
        int n = ar.size();
        int l = 1 , r = n-1;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(ar[m] > ar[0])
                l = m+1;
            else
                ans = ar[m] , r = m-1;
        }
        return ans;
    }
};