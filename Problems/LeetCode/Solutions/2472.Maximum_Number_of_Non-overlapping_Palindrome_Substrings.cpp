class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> nxt(n,n);
        for( int i = 0 ; i < n ; i++ )
            for( int l=i , r=i , len=1 ; l >= 0 && r < n && s[l]==s[r] ; l-- , r++ , len+=2 )
                if(len >= k)
                    nxt[l] = min(nxt[l],r);
        for( int i = 0 ; i < n ; i++ )
            for( int l=i , r=i+1 , len=2 ; l >= 0 && r < n && s[l]==s[r] ; l-- , r++ , len+=2 )
                if(len >= k)
                    nxt[l] = min(nxt[l],r);
        vector<int> dp(n+1,0);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            dp[i] = dp[i+1];
            if(nxt[i] != n)
                dp[i] = max(dp[i],dp[nxt[i]+1]+1);
        }
        return dp[0];
    }
};
