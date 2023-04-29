class Solution {
public:
    static const int maxn = 150;
    string dp[maxn][maxn];
    string f(string& s , int l , int r) {
        string t = s+s;
        int idx = t.find(s,1);
        int times = s.length()/idx;
        return to_string(times)+"["+dp[l][l+idx-1]+"]";
    }
    string encode(string s) {
        int n = s.length();
        for( int len = 1 ; len <= n ; len++ )
            for( int l = 0 ; l <= n-len ; l++ ) {
                int r = l+len-1;
                string sub = s.substr(l,len);
                dp[l][r] = sub;
                for( int i = l+1 ; i <= r ; i++ ) {
                    string temp = dp[l][i-1]+dp[i][r];
                    if(temp.length() < dp[l][r].length())
                        dp[l][r] = temp;
                }
                string temp = f(sub,l,r);
                if(temp.length() < dp[l][r].length())
                    dp[l][r] = temp;
            }
        return dp[0][n-1];
    }
};
