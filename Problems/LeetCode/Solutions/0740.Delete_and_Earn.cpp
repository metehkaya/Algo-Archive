#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int n;
    int dp[20000];
    vector<pi> v;
    int f(int i) {
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        dp[i] = f(i+1);
        int nxt = i+1;
        if(nxt < n && v[i].fi+1 == v[nxt].fi)
            nxt++;
        dp[i] = max(dp[i],f(nxt)+v[i].fi*v[i].se);
        return dp[i];
    }
    int deleteAndEarn(vector<int>& ar) {
        n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            v.pb(pi(ar[i],j-i));
        }
        n = v.size();
        memset(dp,-1,sizeof(dp));
        return f(0);
    }
};