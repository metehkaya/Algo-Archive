typedef long long LL;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        hcuts.push_back(0);
        hcuts.push_back(h);
        vcuts.push_back(0);
        vcuts.push_back(w);
        int n = hcuts.size();
        int m = vcuts.size();
        int mxh = 0 , mxv = 0;
        sort( hcuts.begin() , hcuts.end() );
        sort( vcuts.begin() , vcuts.end() );
        for( int i = 1 ; i < n ; i++ )
            mxh = max( mxh , hcuts[i] - hcuts[i-1] );
        for( int i = 1 ; i < m ; i++ )
            mxv = max( mxv , vcuts[i] - vcuts[i-1] );
        return ( (LL) mxh * mxv ) %  MOD;
    }
};