typedef long long LL;

class Solution {
public:
    int xorBeauty(vector<int>& v) {
        LL n = v.size();
        int ans = 0;
        for( int b = 0 ; b < 30 ; b++ ) {
            LL cnt1 = 0;
            for( int i = 0 ; i < n ; i++ )
                if(v[i] & (1<<b))
                    cnt1++;
            LL cnt0 = n-cnt1;
            LL add = n*n - cnt0*cnt0;
            add *= cnt1;
            if(add % 2 == 1)
                ans += (1<<b);
        }
        return ans;
    }
};
