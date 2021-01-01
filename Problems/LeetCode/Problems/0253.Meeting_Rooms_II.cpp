#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ ) {
            v.pb(pi(ar[i][0],+1));
            v.pb(pi(ar[i][1],-1));
        }
        int curr = 0 , mx = 0;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < 2*n ; i++ ) {
            curr += v[i].se;
            mx = max(mx,curr);
        }
        return mx;
    }
};