class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int ans = -1;
        int n = a.size();
        for( int k = 1 ; k <= 6 ; k++ ) {
            int cntA=0,cntB=0;
            for( int i = 0 ; i < n && (cntA != -1 || cntB != -1) ; i++ ) {
                if( a[i] != k && b[i] == k && cntA != -1 )
                    cntA++;
                else if( a[i] != k && b[i] != k )
                    cntA = -1;
                if( b[i] != k && a[i] == k && cntB != -1 )
                    cntB++;
                else if( b[i] != k && a[i] != k )
                    cntB = -1;
            }
            if( cntA != -1 && ( ans == -1 || cntA <= ans ) )
                ans = cntA;
            if( cntB != -1 && ( ans == -1 || cntB <= ans ) )
                ans = cntB;
        }
        return ans;
    }
};