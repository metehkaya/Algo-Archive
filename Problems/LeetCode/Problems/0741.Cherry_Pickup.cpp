typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution {
public:
    int getBest( int s , int r1 , int c1 , int r2 , int c2 , viii& dp ) {
        int best = -1;
        if(r1 && r2)
            best = max( best , dp[s][r1-1][r2-1] );
        if(r1 && c2)
            best = max( best , dp[s][r1-1][r2] );
        if(c1 && r2)
            best = max( best , dp[s][r1][r2-1] );
        if(c1 && c2)
            best = max( best , dp[s][r1][r2] );
        return best;
    }
    int cherryPickup(vii& ar) {
        int n = ar.size();
        viii dp(2*n-1,vii(n,vi(n,-1)));
        dp[0][0][0] = ar[0][0];
        for( int step = 1 ; step <= 2*n-2 ; step++ ) {
            for( int r1 = 0 ; r1 <= step && r1 < n ; r1++ ) {
                int c1 = step - r1;
                if(c1 >= n)
                    continue;
                for( int r2 = 0 ; r2 <= step && r2 < n ; r2++ ) {
                    int c2 = step - r2;
                    if(c2 >= n)
                        continue;
                    if(ar[r1][c1] == -1 || ar[r2][c2] == -1)
                        continue;
                    int best = getBest(step-1,r1,c1,r2,c2,dp);
                    
                    if(best == -1)
                        continue;
                    dp[step][r1][r2] = best + ar[r1][c1];
                    if(r1 != r2 || c1 != c2)
                        dp[step][r1][r2] += ar[r2][c2];
                }
            }
        }
        return max(dp[2*n-2][n-1][n-1],0);
    }
};