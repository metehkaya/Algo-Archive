class Solution {
public:
    int n,m,M,ic,ec;
    const static int MAXM = 243;
    int dp[MAXM][5][7][7];
    int st[MAXM][5];
    int cnt[MAXM][3];
    int score[MAXM];
    int addScore[MAXM][MAXM];
    int f(int bmask , int row , int ic , int ec) {
        if(row == n)
            return 0;
        if(dp[bmask][row][ic][ec] != -1)
            return dp[bmask][row][ic][ec];
        dp[bmask][row][ic][ec] = 0;
        for( int i = 0 ; i < M ; i++ )
            if(cnt[i][1] <= ic && cnt[i][2] <= ec)
                dp[bmask][row][ic][ec] = max( dp[bmask][row][ic][ec] , f(i,row+1,ic-cnt[i][1],ec-cnt[i][2]) + score[i]+addScore[bmask][i] );
        return dp[bmask][row][ic][ec];
    }
    int getMaxGridHappiness(int n, int m, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        ic = introvertsCount;
        ec = extrovertsCount;
        memset(dp,-1,sizeof(dp));
        M = 1;
        for( int i = 0 ; i < m ; i++ )
            M *= 3;
        for( int i = 0 ; i < M ; i++ ) {
            int temp = i;
            for( int j = 0 ; j < m ; j++ ) {
                st[i][j] = temp % 3;
                temp /= 3;
            }
        }
        memset(cnt,0,sizeof(cnt));
        memset(addScore,0,sizeof(addScore));
        for( int i = 0 ; i < M ; i++ ) {
            for( int j = 0 ; j < m ; j++ )
                cnt[i][st[i][j]]++;
            score[i] = cnt[i][1]*120 + cnt[i][2]*40;
            for( int j = 0 ; j < m-1 ; j++ )
                if(st[i][j] > 0 && st[i][j+1] > 0) {
                    if(st[i][j] == 1)
                        score[i] -= 30;
                    else
                        score[i] += 20;
                    if(st[i][j+1] == 1)
                        score[i] -= 30;
                    else
                        score[i] += 20;
                }
            for( int i2 = 0 ; i2 < M ; i2++ )
                for( int j = 0 ; j < m ; j++ )
                    if(st[i][j] > 0 && st[i2][j] > 0) {
                        if(st[i][j] == 1)
                            addScore[i][i2] -= 30;
                        else
                            addScore[i][i2] += 20;
                        if(st[i2][j] == 1)
                            addScore[i][i2] -= 30;
                        else
                            addScore[i][i2] += 20;
                    }
        }
        return f(0,0,ic,ec);
    }
};