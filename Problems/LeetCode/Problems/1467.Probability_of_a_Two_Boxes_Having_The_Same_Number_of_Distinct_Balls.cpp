typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<double> vd;
typedef vector<vd> vdd;
typedef vector<vdd> vddd;
typedef vector<vddd> vdddd;

class Solution {
public:
    const int MAXVAL = 7;
    const int MAXSUM = 49;
    double f( int id , int rem1 , int rem2 , int cnt1 , int cnt2 , int n , vi& ar , vii& comb , vdddd& dp ) {
        if(id == n)
            return cnt1 == cnt2;
        if( dp[id][rem1][cnt1][cnt2] >= 0 )
            return dp[id][rem1][cnt1][cnt2];
        dp[id][rem1][cnt1][cnt2] = 0.0;
        int totalWays = comb[rem1+rem2][ar[id]];
        for( int i = 0 ; i <= ar[id] ; i++ ) {
            int j = ar[id] - i;
            if( i <= rem1 && j <= rem2 ) {
                int ways = comb[rem1][i] * comb[rem2][j];
                double r = (double) ways / totalWays;
                int ncnt1 = cnt1 + (i > 0);
                int ncnt2 = cnt2 + (j > 0);
                dp[id][rem1][cnt1][cnt2] += r * f( id+1 , rem1-i , rem2-j , ncnt1 , ncnt2 , n , ar , comb , dp );
            }
        }
        return dp[id][rem1][cnt1][cnt2];
    }
    double getProbability(vi& ar) {
        vii comb(MAXSUM,vi(MAXVAL,0));
        for( int i = 0 ; i < MAXSUM ; i++ )
            comb[i][0] = 1;
        for( int i = 1 ; i < MAXSUM ; i++ )
            for( int j = 1 ; j < MAXVAL ; j++ )
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        int n = ar.size() , sum = 0;
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        vdddd dp( n , vddd( sum/2+1 , vdd( n+1 , vd( n+1 , -1.0 ) ) ) );
        return f( 0 , sum/2 , sum/2 , 0 , 0 , n , ar , comb , dp );
    }
};