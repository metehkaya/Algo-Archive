#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int n;
    vector<pi> v;
    vector<string> findRelativeRanks(vector<int>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(ar[i],i));
        sort(v.begin(),v.end());
        vector<string> ans(n);
        for( int i = 0 ; i < n ; i++ ) {
            int idx = v[i].se;
            int place = n-i;
            if(place == 1)
                ans[idx] = "Gold Medal";
            else if(place == 2)
                ans[idx] = "Silver Medal";
            else if(place == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(place);
        }
        return ans;
    }
};