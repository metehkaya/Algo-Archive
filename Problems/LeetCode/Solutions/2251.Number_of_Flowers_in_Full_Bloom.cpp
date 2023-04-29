#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = flowers.size();
        int m = persons.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ ) {
            v.pb(pi(flowers[i][0],-1));
            v.pb(pi(flowers[i][1]+1,-2));
        }
        for( int i = 0 ; i < m ; i++ )
            v.pb(pi(persons[i],i));
        int cnt = 0;
        vector<int> ans(m);
        sort(v.begin(),v.end());
        for( int i = 0 ; i < 2*n+m ; i++ ) {
            if(v[i].se == -1)
                cnt++;
            else if(v[i].se == -2)
                cnt--;
            else
                ans[v[i].se] = cnt;
        }
        return ans;
    }
};
