#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({a[i],b[i]});
        sort(v.begin() , v.end() , [&](pi& x , pi& y) {
            return x.fi - y.se > y.fi - x.se;
        });
        int diff = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(i % 2 == 0)
                diff += v[i].fi;
            else
                diff -= v[i].se;
        }
        if(diff > 0)
            return 1;
        else if(diff < 0)
            return -1;
        return 0;
    }
};