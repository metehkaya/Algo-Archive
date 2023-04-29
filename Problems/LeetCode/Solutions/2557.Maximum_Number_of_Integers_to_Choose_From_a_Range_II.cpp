typedef long long LL;

class Solution {
public:
    int maxCount(vector<int>& v, int n, LL maxSum) {
        LL total = 0 , cnt = 0;
        sort(v.begin(),v.end());
        map<int,vector<LL>> mp;
        mp[0] = {0,0};
        int prev_x = -1;
        for(int x : v) {
            if(x == prev_x)
                continue;
            prev_x = x;
            cnt++;
            total += x;
            mp[x] = {total,cnt};
        }
        LL l = 1 , r = n , ans;
        while(l <= r) {
            LL m = (l+r) >> 1;
            LL sum = m*(m+1)/2;
            auto it = mp.upper_bound(m);
            it--;
            sum -= it->second[0];
            if(sum <= maxSum)
                ans = m-it->second[1] , l = m+1;
            else
                r = m-1;
        }
        return (int) ans;
    }
};
