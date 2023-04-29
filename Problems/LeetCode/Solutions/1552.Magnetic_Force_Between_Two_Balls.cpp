class Solution {
public:
    int maxDistance(vector<int>& ar, int m) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int l = 1 , r = ar[n-1] , ans = 0;
        while(l <= r) {
            int mid = (l+r)>>1;
            int i = 1 , curr = ar[0] , cnt = 1;
            while(cnt < m && i < n) {
                if(ar[i] >= curr+mid)
                    curr = ar[i] , cnt++;
                i++;
            }
            if(cnt == m)
                l = mid+1 , ans = mid;
            else
                r = mid-1;
        }
        return ans;
    }
};