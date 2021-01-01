typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    bool check( int a , int b , int m ) {
        for( int i = 0 ; i < m ; i++ )
            if( a & (1<<i) ) {
                int j = i-1 , k = i+1;
                if(j >= 0)
                    if( (a & (1<<j)) || (b & 1<<j) )
                        return false;
                if(k < m)
                    if( (a & (1<<k)) || (b & 1<<k) )
                        return false;
            }
        return true;
    }
    int f( int row , int old , int n , int m , int M , vi& cnt , vi& av , vii& dp ) {
        if(row == n)
            return 0;
        if(dp[row][old] != -1)
            return dp[row][old];
        dp[row][old] = 0;
        for( int i = 0 ; i < M ; i++ )
            if( ( av[row] & i ) == i )
                if( check( i , old , m ) )
                    dp[row][old] = max( dp[row][old] , f( row+1 , i , n , m , M , cnt , av , dp ) + cnt[i] );
        return dp[row][old];
    }
    int maxStudents(vector<vector<char>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vi av(n,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == '.' )
                    av[i] = ( av[i] | (1<<j) );
        int M = (1<<m);
        vi cnt( M , 0 );
        for( int i = 1 ; i < M ; i++ )
            cnt[i] = cnt[i-(i&(-i))] + 1;
        vii dp( n , vi( M , -1 ) );
        return f(0,0,n,m,M,cnt,av,dp);
    }
};