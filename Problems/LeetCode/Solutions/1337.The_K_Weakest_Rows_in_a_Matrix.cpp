typedef pair<int,int> pi;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& ar, int k) {
        vector<pi> v;
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ ) {
            int j;
            for( j = 0 ; j < m && ar[i][j] == 1 ; j++ );
            v.push_back(pi(j,i));
        }
        sort( v.begin() , v.end() );
        vector<int> ans;
        for( int i = 0 ; i < k ; i++ )
            ans.push_back(v[i].second);
        return ans;
    }
};