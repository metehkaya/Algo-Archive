#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int minimumOperations(vector<int>& ar) {
        int n = ar.size();
        if(n == 1)
            return 0;
        map<int,int> mp[2];
        int nc[2] = {(n+1)/2,n/2};
        mp[0][100001] = nc[0];
        mp[1][100002] = nc[1];
        for( int i = 0 ; i < n ; i++ ) {
            int k = i%2;
            if(mp[k].find(ar[i]) == mp[k].end())
                mp[k][ar[i]] = nc[k]-1;
            else
                mp[k][ar[i]]--;
        }
        int ans = n;
        vector<pi> v[2];
        for( int k = 0 ; k < 2 ; k++ )
            for( auto it : mp[k] )
                v[k].push_back(pi(it.se,it.fi));
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < 2 ; j++ )
                if(v[0][i].se != v[1][j].se)
                    ans = min(ans,v[0][i].fi+v[1][j].fi);
        return ans;
    }
};
