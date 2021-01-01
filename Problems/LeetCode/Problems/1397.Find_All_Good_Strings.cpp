typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution {
public:
    const int K = 26;
    const int MOD = (int) 1e9 + 7;
    void findNext( string& s , int n , vii& nxt ) {
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < K ; j++ ) {
                string t = s.substr(0,i);
                char c = 'a' + j;
                t.push_back(c);
                for( int k = i+1 ; k >= 1 ; k-- )
                    if( t.substr(i+1-k,k) == s.substr(0,k) ) {
                        nxt[i][j] = k;
                        break;
                    }
            }
    }
    int f( int curr , int index , bool bigger , bool smaller , int n , int m , string& s , string& t , vii& nxt , viii& dp ) {
        if(curr == n)
            return 1;
        int k = bigger*2+smaller;
        if(dp[curr][index][k] != -1)
            return dp[curr][index][k];
        dp[curr][index][k] = 0;
        int x = s[curr]-'a';
        int y = t[curr]-'a';
        for( int i = 0 ; i < K ; i++ ) {
            if(i < x && !bigger)
                continue;
            if(i > y && !smaller)
                continue;
            int val = nxt[index][i];
            if(val == m)
                continue;
            dp[curr][index][k] += f(curr+1,val,bigger||(i>x),smaller||(i<y),n,m,s,t,nxt,dp);
            dp[curr][index][k] %= MOD;
        }
        return dp[curr][index][k];
    }
    int findGoodStrings(int n, string s, string t, string evil) {
        int m = evil.length();
        vii nxt(m,vi(K,0));
        findNext( evil , m , nxt );
        viii dp(n,vii(m,vi(4,-1)));
        return f(0,0,false,false,n,m,s,t,nxt,dp);
    }
};