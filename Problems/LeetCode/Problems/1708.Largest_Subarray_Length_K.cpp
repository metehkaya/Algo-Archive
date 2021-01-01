#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> largestSubarray(vector<int>& ar, int k) {
        int n = ar.size();
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(ar[i],i));
        sort(v.begin(),v.end());
        vector<int> ans;
        for( int i = n-1 ; i >= 0 ; i-- )
            if(v[i].se <= n-k) {
                int idx = v[i].se;
                for( int j = idx ; j < idx+k ; j++ )
                    ans.push_back(ar[j]);
                break;
            }
        return ans;
    }
};