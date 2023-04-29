typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int BIG = (int) 1e9;
    int f(int i , int j , int n , int m , vi& a , vi& b , vi& bigger , vii& dp) {
        if(i == a.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = BIG;
        if(j == m) {
            if(a[i] > a[i-1])
                dp[i][j] = min(dp[i][j] , f(i+1,m,n,m,a,b,bigger,dp));
            if(bigger[i-1] < m)
                dp[i][j] = min(dp[i][j] , f(i+1,bigger[i-1],n,m,a,b,bigger,dp)+1);
        }
        else {
            if(a[i] > b[j])
                dp[i][j] = min(dp[i][j] , f(i+1,m,n,m,a,b,bigger,dp));
            if(j+1 < m)
                dp[i][j] = min(dp[i][j] , f(i+1,j+1,n,m,a,b,bigger,dp)+1);
        }
        return dp[i][j];
    }
    int makeArrayIncreasing(vi& a, vi& B) {
        int n = a.size();
        int m = B.size();
        sort(B.begin() , B.end());
        vi b;
        for( int i = 0 , j = 0 ; i < m ; i = j ) {
            b.push_back(B[i]);
            while(j < m && B[i] == B[j])
                j++;
        }
        m = b.size();
        vi bigger(n,m);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(a[i] < b[j]) {
                    bigger[i] = j;
                    break;
                }
        vii dp(n,vi(m+1,-1));
        int ans = f(1,m,n,m,a,b,bigger,dp);
        ans = min(ans , f(1,0,n,m,a,b,bigger,dp)+1);
        return (ans < BIG) ? ans : -1;
    }
};