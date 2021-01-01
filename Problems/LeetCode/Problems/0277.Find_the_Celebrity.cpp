bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<int>>G(n,vector<int>(n,-1));
        for( int i = 0 ; i < n ; i++ ) {
            bool isCeleb = true;
            for( int j = 0 ; j < n ; j++ )
                if(i != j) {
                    if(G[i][j] == -1)
                        G[i][j] = knows(i,j);
                    if(G[i][j]) {
                        isCeleb = false;
                        break;
                    }
                    if(G[j][i] == -1)
                        G[j][i] = knows(j,i);
                    if(!G[j][i]) {
                        isCeleb = false;
                        break;
                    }
                }
            if(isCeleb)
                return i;
        }
        return -1;
    }
};