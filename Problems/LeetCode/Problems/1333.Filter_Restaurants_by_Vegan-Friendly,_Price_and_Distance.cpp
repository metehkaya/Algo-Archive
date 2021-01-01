#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& ar, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pi> v;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if( veganFriendly && !ar[i][2] )
                continue;
            if( ar[i][3] > maxPrice || ar[i][4] > maxDistance )
                continue;
            v.push_back( pi( ar[i][1] , ar[i][0] ) );
        }
        sort( v.begin() , v.end() );
        vector<int> ans;
        for( int i = v.size() - 1 ; i >= 0 ; i-- )
            ans.push_back( v[i].se );
        return ans;
    }
};