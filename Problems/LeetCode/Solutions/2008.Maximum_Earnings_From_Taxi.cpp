#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    static const int maxn = 100001;
    long long dp[maxn];
    vector<pi> v[maxn];
    long long maxTaxiEarnings(int n, vector<vector<int>>& ar) {
        int m = ar.size();
        for( int i = 0 ; i < m ; i++ )
            v[ar[i][0]].pb(pi(ar[i][1],ar[i][2]+ar[i][1]-ar[i][0]));
        for( int i = 1 ; i <= n ; i++ ) {
            if(i-1)
                dp[i] = max(dp[i],dp[i-1]);
            int sz = v[i].size();
            for( int j = 0 ; j < sz ; j++ )
                dp[v[i][j].fi] = max(dp[v[i][j].fi],dp[i]+v[i][j].se);
        }
        return dp[n];
    }
};