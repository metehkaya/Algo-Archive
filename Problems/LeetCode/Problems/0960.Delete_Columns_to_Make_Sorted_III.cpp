typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    bool check(int c1 , int c2 , vector<string>& ar , int n) {
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][c1] < ar[i][c2])
                return false;
        return true;
    }
    int f(int col , int last , int n , int m , vector<string>& ar , vii& dp) {
        if(col == m)
            return 0;
        if(dp[col][last] != -1)
            return dp[col][last];
        dp[col][last] = f(col+1,last,n,m,ar,dp) + 1;
        if(last == 0 or check(col,last-1,ar,n))
            dp[col][last] = min( dp[col][last] , f(col+1,col+1,n,m,ar,dp) );
        return dp[col][last];
    }
    int minDeletionSize(vector<string>& ar) {
        int n = ar.size() , m = ar[0].size();
        vii dp(m,vi(m+1,-1));
        return f(0,0,n,m,ar,dp);
    }
};