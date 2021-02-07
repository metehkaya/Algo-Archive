#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    int maxValue(vector<vector<int>>& ar, int k) {
        int n = ar.size();
        vector<pii> v;
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i][0]] = mp[ar[i][1]] = 0;
        int N = 0;
        for(auto it : mp)
            mp[it.fi] = N++;
        for( int i = 0 ; i < n ; i++ ) {
            ar[i][0] = mp[ar[i][0]];
            ar[i][1] = mp[ar[i][1]];
        }
        int dp[k][N];
        memset(dp,0,sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            dp[0][ar[i][1]] = max(dp[0][ar[i][1]],ar[i][2]);
        for( int i = 1 ; i < N ; i++ )
            dp[0][i] = max(dp[0][i],dp[0][i-1]);
        for( int i = 1 ; i < k ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                int bef = ar[j][0];
                if(bef > 0)
                    dp[i][ar[j][1]] = max(dp[i][ar[j][1]],dp[i-1][bef-1]+ar[j][2]);
            }
            for( int j = 1 ; j < N ; j++ )
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
        int ans = 0;
        for( int i = 0 ; i < k ; i++ )
            for( int j = 0 ; j < N ; j++ )
                ans = max(ans,dp[i][j]);
        return ans;
    }
};