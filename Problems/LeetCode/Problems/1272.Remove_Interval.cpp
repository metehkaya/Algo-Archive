typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vi getVec(int s, int e) {
        vi res(2);
        res[0] = s;
        res[1] = e;
        return res;
    }
    vvi removeInterval(vvi& ar, vi& removal) {
        vvi ans;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if( removal[0] <= ar[i][0] && ar[i][1] <= removal[1] )
                continue;
            else if( ar[i][0] <= removal[0] && removal[1] <= ar[i][1] ) {
                if( ar[i][0] < removal[0] )
                    ans.push_back( getVec( ar[i][0] , removal[0] ) );
                if( removal[1] < ar[i][1] )
                    ans.push_back( getVec( removal[1] , ar[i][1] ) );
            }
            else if( ar[i][1] < removal[0] || removal[1] < ar[i][0] )
                ans.push_back( ar[i] );
            else if( ar[i][0] <= removal[0] && removal[0] <= ar[i][1] )
                ans.push_back( getVec( ar[i][0] , removal[0] ) );
            else if( ar[i][0] <= removal[1] && removal[1] <= ar[i][1] )
                ans.push_back( getVec( removal[1] , ar[i][1] ) );
        }
        return ans;
    }
};