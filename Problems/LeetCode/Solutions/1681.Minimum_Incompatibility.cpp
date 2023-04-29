class Solution {
public:
    int cnt[17];
    int minimumIncompatibility(vector<int>& ar, int k) {
        int n = ar.size();
        int N = (1<<n);
        vector<int> val(N,-1);
        for( int bmask = 1 ; bmask < N ; bmask++ )
            if(__builtin_popcount(bmask) == n / k) {
                memset(cnt,0,sizeof(cnt));
                for( int i = 0 ; i < n ; i++ )
                    if(bmask & (1<<i))
                        cnt[ar[i]]++;
                int l = INT_MAX , r = INT_MIN;
                bool ok = true;
                for( int i = 1 ; i <= n ; i++ ) {
                    if(cnt[i] > 1) {
                        ok = false;
                        break;
                    }
                    else if(cnt[i] == 1) {
                        l = min(l,i);
                        r = max(r,i);
                    }
                }
                if(ok)
                    val[bmask] = r-l;
            }
        vector<int> dp(N,-1);
        dp[0] = 0;
        for( int bmask = 1 ; bmask < N ; bmask++ )
            if(__builtin_popcount(bmask) % (n/k) == 0)
                for( int x = bmask ; x > 0 ; x = bmask & (x-1) )
                    if(val[x] != -1 && dp[bmask-x] != -1) {
                        int temp = val[x] + dp[bmask-x];
                        if(dp[bmask] == -1 || dp[bmask] > temp)
                            dp[bmask] = temp;
                    }
        return dp[N-1];
    }
};