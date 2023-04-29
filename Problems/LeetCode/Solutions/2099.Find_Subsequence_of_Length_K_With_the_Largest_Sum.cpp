#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& ar, int k) {
        int n = ar.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(ar[i],i));
        sort(v.begin(),v.end());
        vector<int> indices;
        for( int i = n-k ; i < n ; i++ )
            indices.pb(v[i].se);
        sort(indices.begin(),indices.end());
        vector<int> ans;
        for( int i = 0 ; i < k ; i++ )
            ans.push_back(ar[indices[i]]);
        return ans;
    }
};
