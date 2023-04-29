#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(growTime[i],plantTime[i]));
        sort(v.begin(),v.end());
        int t = 0 , ans = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            t += v[i].se;
            ans = max(ans,t+v[i].fi);
        }
        return ans;
    }
};
