class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& ar, int h, int w) {
        int n = ar.size();
        int m = ar[0].size();
        bool boost[n][m];
        memset(boost,false,sizeof(boost));
        vector<int> currh(m,0);
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 0)
                    currh[j]++;
                else
                    currh[j] = 0;
            for( int l = 0 , r = 0 ; l < m ; l = r+1 ) {
                r = l;
                while(r < m && currh[r] >= h)
                    r++;
                if(r-l >= w)
                    for( int j = l ; j < r ; j++ )
                        boost[i][j] = true;
            }
        }
        for( int i = 0 ; i < m ; i++ )
            currh[i] = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(boost[i][j])
                    currh[j] = h;
                if(ar[i][j] == 0 && currh[j] == 0)
                    return false;
                currh[j] = max(currh[j]-1,0);
            }
        }
        return true;
    }
};
