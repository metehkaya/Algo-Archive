typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int DIR[4] = {0,1,0,-1};
    int uniquePathsIII(vii& ar) {
        int n = ar.size() , m = ar[0].size();
        int si , sj , ei , ej , sBM = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int add = (1<<(i*m+j));
                if(ar[i][j] == 1)
                    si = i , sj = j , sBM |= add;
                else if(ar[i][j] == 2)
                    ei = i , ej = j;
                else if(ar[i][j] == -1)
                    sBM |= add;
            }
        int N = (1<<(n*m));
        vii dp(N,vi(n*m,0));
        dp[sBM][si*m+sj] = 1;
        for( int bm = sBM ; bm < N-1 ; bm++ )
            for( int r = 0 ; r < n ; r++ )
                for( int c = 0 ; c < m ; c++ )
                    if(dp[bm][r*m+c])
                        for( int i = 0 ; i < 4 ; i++ ) {
                            int x = r + DIR[i];
                            int y = c + DIR[i^1];
                            if(x == -1 or x == n or y == -1 or y == m)
                                continue;
                            int add = (1<<(x*m+y));
                            if(bm & (add))
                                continue;
                            dp[bm|add][x*m+y] += dp[bm][r*m+c];
                        }
        return dp[N-1][ei*m+ej];
    }
};