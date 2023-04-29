typedef pair<int,int> pi;

class Solution {
public:
    int longestSubarray(vector<int>& ar) {
        vector<pi> v;
        int n = ar.size() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            if(ar[i] == 1) {
                v.push_back(pi(i,j));
                ans = max(ans,j-i);
            }
        }
        int sz = v.size();
        if(sz == 0)
            return 0;
        if(sz == 1) {
            if(v[0].first == 0 && v[0].second == n)
                return n-1;
            return v[0].second - v[0].first;
        }
        for( int i = 0 ; i < sz-1 ; i++ )
            if(v[i].second + 1 == v[i+1].first)
                ans = max( ans , v[i+1].second - v[i].first - 1 );
        return ans;
    }
};