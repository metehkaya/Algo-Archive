#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> frequencySort(vector<int>& ar) {
        map<int,int> cnt;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        vector<pi> v;
        for(auto it : cnt)
            v.pb(pi(it.first,it.second));
        sort(v.begin() , v.end() , [](pi a , pi b) {
            if(a.se != b.se)
                return a.se < b.se;
            return a.fi > b.fi;
        });
        vector<int> ans;
        for( int i = 0 ; i < v.size() ; i++ )
            for( int j = 0 ; j < v[i].se ; j++ )
                ans.pb(v[i].fi);
        return ans;
    }
};