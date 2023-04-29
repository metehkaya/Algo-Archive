class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        int combo[n][m];
        memset(combo,0,sizeof(combo));
        for( int times = 1 , cont = 1 ; cont ; times++ ) {
            cont = 0;
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < m ; j++ ) {
                    if(i > 0 && i < n-1 && ar[i][j])
                        if(ar[i][j] == ar[i-1][j] && ar[i][j] == ar[i+1][j]) {
                            cont = 1;
                            combo[i][j] = combo[i-1][j] = combo[i+1][j] = times;
                        }
                    if(j > 0 && j < m-1 && ar[i][j])
                        if(ar[i][j] == ar[i][j-1] && ar[i][j] == ar[i][j+1]) {
                            cont = 1;
                            combo[i][j] = combo[i][j-1] = combo[i][j+1] = times;
                        }
                }
            for( int j = 0 ; j < m ; j++ ) {
                int idx = n-1;
                for( int i = n-1 ; i >= 0 ; i-- )
                    if(combo[i][j] != times)
                        ar[idx--][j] = ar[i][j];
                while(idx >= 0)
                    ar[idx--][j] = 0;
            }
        }
        return ar;
    }
};