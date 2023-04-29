typedef long long LL;

class Solution {
public:
    const static int maxn = 100000;
    const LL mod = (LL) 1e9+7;
    int cnt[maxn+1];
    int sum[maxn+1];
    int sumOfFlooredPairs(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        for( int i = 1 ; i <= maxn ; i++ )
            sum[i] = sum[i-1] + cnt[i];
        LL ans = 0;
        for( int num = 1 ; num <= maxn ; num++ )
            if(cnt[num]) {
                LL add = 0;
                for( int i = num ; i <= maxn ; i += num ) {
                    int j = min(i+num-1,maxn);
                    add += (sum[j]-sum[i-1]) * (i/num);
                    add %= mod;
                }
                add = (add * cnt[num]) % mod;
                ans = (ans + add) % mod;
            }
        return ans;
    }
};