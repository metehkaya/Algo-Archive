typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;

class Solution {
public:
    int twoCitySchedCost(vii& ar) {
        int ans = 0;
        int n = ar.size();
        vi cnt(2,0);
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ ) {
            int smaller = ar[i][0] <= ar[i][1] ? 0 : 1;
            v.push_back( pi( abs( ar[i][0] - ar[i][1] ) , smaller ) );
            ans += min( ar[i][0] , ar[i][1] );
        }
        sort( v.begin() , v.end() );
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int smaller = v[i].second;
            int index = cnt[smaller] < n/2 ? smaller : !smaller;
            cnt[index]++;
            ans += (index != smaller) * v[i].first;
        }
        return ans;
    }
};