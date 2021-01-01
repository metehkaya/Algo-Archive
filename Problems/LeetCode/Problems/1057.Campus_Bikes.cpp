typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& w, vector<vector<int>>& b) {
        int n = w.size();
        int m = b.size();
        vector<pii> dists;
        vector<bool> varW(n);
        vector<bool> varB(m);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                dists.push_back( pii( abs(w[i][0]-b[j][0]) + abs(w[i][1]-b[j][1]) , pi(i,j) ) );
        sort( dists.begin() , dists.end() );
        int cnt = 0;
        vector<int> ans(n,-1);
        for( int i = 0 ; i < n*m && cnt<n ; i++ ) {
            int w = dists[i].second.first;
            int b = dists[i].second.second;
            if(varW[w] || varB[b])
                continue;
            cnt++;
            ans[w] = b;
            varW[w] = varB[b] = true;
        }
        return ans;
    }
};