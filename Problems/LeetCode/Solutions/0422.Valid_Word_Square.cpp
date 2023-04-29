class Solution {
public:
    bool validWordSquare(vector<string>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int sz = ar[i].size();
            for( int j = 0 ; j < sz ; j++ )
                if(j >= n || i >= ar[j].size() || ar[i][j] != ar[j][i])
                    return false;
        }
        return true;
    }
};