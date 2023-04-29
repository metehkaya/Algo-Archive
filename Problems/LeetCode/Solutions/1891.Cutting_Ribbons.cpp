class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1 , r = (int) 1e5 , ans = 0;
        while(l <= r) {
            int cnt = 0 , m = (l+r) >> 1;
            for(int x : ribbons) {
                cnt += x/m;
                if(cnt >= k)
                    break;
            }
            if(cnt >= k)
                ans = m , l = m+1;
            else
                r = m-1;
        }
        return ans;
    }
};
