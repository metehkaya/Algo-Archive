class Solution {
public:
    int minCapability(vector<int>& v, int k) {
        int n = v.size();
        int l = 0 , r = (int) 1e9 , ans = INT_MAX;
        while(l <= r) {
            int mid = (l+r)>>1;
            int i = 0 , cnt = 0;
            while(i < n) {
                if(v[i] <= mid)
                    i += 2 , cnt++;
                else
                    i++;
            }
            if(cnt >= k)
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};
