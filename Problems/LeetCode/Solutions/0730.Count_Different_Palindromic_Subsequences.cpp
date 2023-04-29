typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int f( int l , int r , vii& nextIndex , vii& prevIndex , vii& dp ) {
        if(l > r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        dp[l][r] = 0;
        for( int i = 0 ; i < 4 ; i++ ) {
            int ll = nextIndex[l][i];
            int rr = prevIndex[r][i];
            if(ll > rr)
                continue;
            dp[l][r] = ( dp[l][r] + 1 ) % MOD;
            if(ll < rr)
                dp[l][r] = ( dp[l][r] + f(ll+1,rr-1,nextIndex,prevIndex,dp) + 1 ) % MOD;
        }
        return dp[l][r];
    }
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vii nextIndex( n , vi(4) );
        vii prevIndex( n , vi(4) );
        vi v;
        v.resize(4,n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            v[s[i]-'a'] = i;
            nextIndex[i] = v;
        }
        v.clear();
        v.resize(4,-1);
        for( int i = 0 ; i < n ; i++ ) {
            v[s[i]-'a'] = i;
            prevIndex[i] = v;
        }
        vii dp( n , vi(n,-1) );
        f(0,n-1,nextIndex,prevIndex,dp);
        return dp[0][n-1];
    }
};