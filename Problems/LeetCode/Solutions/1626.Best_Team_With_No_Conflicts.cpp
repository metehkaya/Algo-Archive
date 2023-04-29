#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int n;
    int dp[1000];
    vector<pi> v;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(ages[i],scores[i]));
        sort(v.begin(),v.end());
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < i ; j++ )
                if(v[j].se <= v[i].se)
                    dp[i] = max(dp[i],dp[j]);
            dp[i] += v[i].se;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};