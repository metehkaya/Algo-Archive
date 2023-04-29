class Solution {
public:
    void upd(short& cell , int val) {
        if(cell == -1 or val < cell)
            cell = val;
    }
    int getDig(int n) {
        if(n >= 100)
            return 3;
        else if(n >= 10)
            return 2;
        else if(n >= 2)
            return 1;
        return 0;
    }
    int getLengthOfOptimalCompression(string s, int m) {
        int n = s.length();
        vector<int> cnt(27,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a'+1]++;
        short dp[n+1][n+1][27][n+1];
        memset(dp,-1,sizeof(dp));
        dp[0][0][0][0] = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a'+1;
            for( int j = 0 ; j <= i ; j++ )
                for( int k = 0 ; k < 27 ; k++ )
                    for( int t = 0 ; t <= cnt[k] ; t++ )
                        if(dp[i][j][k][t] != -1) {
                            int val = dp[i][j][k][t];
                            if(k == c) {
                                int d1 = getDig(t);
                                int d2 = getDig(t+1);
                                upd(dp[i+1][j][c][t+1],val+d2-d1);
                            }
                            else
                                upd(dp[i+1][j][c][1],val+1);
                            if(j < m)
                                upd(dp[i+1][j+1][k][t],val);
                        }
        }
        short ans = 255;
        for( int i = 0 ; i <= m ; i++ )
            for( int k = 0 ; k < 27 ; k++ )
                for( int t = 0 ; t <= cnt[k] ; t++ )
                    if(dp[n][i][k][t] != -1)
                        ans = min(ans,dp[n][i][k][t]);
        return (int) ans;
    }
};