typedef long long LL;

class Solution {
public:
    LL maxPower(vector<int>& vv, int rad, int k) {
        int n = vv.size();
        vector<LL> sum(n);
        sum[0] = vv[0];
        for( int i = 1 ; i < n ; i++ )
            sum[i] = sum[i-1]+vv[i];
        vector<LL> v(n);
        for( int i = 0 ; i < n ; i++ ) {
            int l = max(0,i-rad);
            int r = min(n-1,i+rad);
            v[i] = sum[r] - ((l == 0) ? 0 : sum[l-1]);
        }
        LL ans = 0;
        LL L = 0 , R = sum[n-1]+k;
        while(L <= R) {
            LL mid = (L+R)>>1;
            LL rem = k , add = 0;
            queue<vector<LL>> q;
            for( int i = 0 ; i < n && rem >= 0 ; i++ ) {
                while(!q.empty() && abs(i-q.front()[0]) > rad) {
                    add -= q.front()[1];
                    q.pop();
                }
                LL val = v[i]+add;
                if(val < mid) {
                    LL diff = mid-val;
                    q.push({i+rad,diff});
                    rem -= diff;
                    add += diff;
                }
            }
            if(rem >= 0)
                ans = mid , L = mid+1;
            else
                R = mid-1;
        }
        return ans;
    }
};
