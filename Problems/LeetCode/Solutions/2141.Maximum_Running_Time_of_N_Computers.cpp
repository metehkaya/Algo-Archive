typedef long long LL;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& ar) {
        LL l = 1 , r = (1LL << 47) , ans = 0;
        while(l <= r) {
            LL sum = 0;
            LL m = (l+r) >> 1;
            for(int x : ar)
                sum += min((LL)x,m);
            if(sum >= m*n)
                ans = m , l = m+1;
            else
                r = m-1;
        }
        return ans;
    }
};
