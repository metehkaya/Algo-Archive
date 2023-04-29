class Solution {
public:
    const int MOD = 1000000007;
    const int DIR[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    pair<int,int> numberToCoor(int i) {
        if(i == 0)
            return make_pair(3,1);
        return make_pair((i-1)/3,(i-1)%3);
    }
    int coorToNumber(int i, int j) {
        if(i<0 || i>3 || j<0 || j>2)
            return -1;
        if(i == 3) {
            if(j == 0 || j == 2)
                return -1;
            return 0;
        }
        return 3*i+j+1;
    }
    int knightDialer(int n) {
        vector<int> dpNew(10,1);
        for( int i = 1 ; i < n ; i++ ) {
            vector<int> dpOld = dpNew;
            for( int j = 0 ; j < 10 ; j++ ) {
                pair<int,int> p = numberToCoor(j);
                int r = p.first;
                int c = p.second;
                dpNew[j] = 0;
                for( int k = 0 ; k < 8 ; k++ ) {
                    int r2 = r+DIR[k][0];
                    int c2 = c+DIR[k][1];
                    int number = coorToNumber(r2,c2);
                    if(number != -1)
                        dpNew[j] = ( dpNew[j] + dpOld[number] ) % MOD;
                }
            }
        }
        int ans = 0;
        for( int i = 0 ; i < 10 ; i++ )
            ans = ( dpNew[i] + ans ) % MOD;
        return ans;
    }
};