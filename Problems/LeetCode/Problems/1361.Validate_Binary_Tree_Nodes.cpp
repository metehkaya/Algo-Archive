class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> cntPar(n,0);
        vector<int> cntPar2(2,0);
        for( int i = 0 ; i < n ; i++ ) {
            if(l[i] == r[i] && l[i] != -1)
                return false;
            if(l[i] != -1)
                cntPar[l[i]]++;
            if(r[i] != -1)
                cntPar[r[i]]++;
        }
        for( int i = 0 ; i < n ; i++ ) {
            if(cntPar[i] == 0 && l[i] == -1 && r[i] == -1 && n > 1)
                return false;
            if(cntPar[i] >= 2)
                return false;
            cntPar2[cntPar[i]]++;
        }
        if(cntPar2[0] != 1 || cntPar2[1] != n-1)
            return false;
        return true;
    }
};