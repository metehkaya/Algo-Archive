class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<int> cntR(n,0);
        vector<int> cntC(m,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 'B')
                    cntR[i]++ , cntC[j]++;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 'B')
                    ans += (cntR[i] == 1 && cntC[j] == 1);
        return ans;
    }
};