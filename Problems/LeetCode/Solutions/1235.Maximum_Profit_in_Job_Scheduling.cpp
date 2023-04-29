typedef pair<int,int> pi;

class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        vector<int> v;
        int n = st.size();
        for( int i = 0 ; i < n ; i++ ) {
            v.push_back(st[i]);
            v.push_back(et[i]);
        }
        sort( v.begin() , v.end() );
        int k = 0;
        map<int,int> hashh;
        for( int i = 0 , j = 0 ; i < 2*n ; i = j ) {
            hashh[v[i]] = ++k;
            while(j < 2*n && v[i] == v[j])
                j++;
        }
        vector<int> dp(k+1,0);
        vector<vector<pi>> add(k+1);
        for( int i = 0 ; i < n ; i++ )
            add[hashh[st[i]]].push_back( pi( hashh[et[i]] , p[i] ) );
        for( int i = 1 ; i <= k ; i++ ) {
            dp[i] = max( dp[i] , dp[i-1] );
            for( int j = 0 ; j < add[i].size() ; j++ )
                dp[ add[i][j].first ] = max( dp[ add[i][j].first ] , dp[i] + add[i][j].second );
        }
        return dp[k];
    }
};