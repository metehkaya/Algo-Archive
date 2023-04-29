class Solution {
public:
    long long minimumTime(vector<int>& v) {
        int n = v.size();
        int N = (1<<n);
        vector<long long> dp(N,LLONG_MAX);
        dp[0] = 0;
        for( int bmask = 1 ; bmask < N ; bmask++ ) {
            vector<int> indices;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    indices.push_back(i);
            int cnt = (int) indices.size();
            for(int idx : indices) {
                int bmask2 = (bmask ^ (1<<idx));
                long long cost = (v[idx]+cnt-1) / cnt;
                dp[bmask] = min(dp[bmask],dp[bmask2]+cost);
            }
        }
        return dp[N-1];
    }
};
