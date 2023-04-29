typedef long long LL;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        LL l = 1 , r = INT_MAX , ans = 0;
        while(l <= r) {
            LL m = (l+r)>>1 , cnt = 0;
            for(int x : candies)
                cnt += x/m;
            if(cnt >= k)
                ans = m , l = m+1;
            else
                r = m-1;
        }
        return ans;
    }
};
