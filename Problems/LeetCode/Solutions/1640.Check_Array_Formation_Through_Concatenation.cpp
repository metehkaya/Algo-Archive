class Solution {
public:
    bool canFormArray(vector<int>& ar, vector<vector<int>>& pieces) {
        int n = ar.size();
        int m = pieces.size();
        for( int i = 0 ; i < n ; ) {
            bool ok = false;
            for( int j = 0 ; j < m ; j++ )
                if(ar[i] == pieces[j][0]) {
                    ok = true;
                    int len = pieces[j].size();
                    for( int k = 0 ; k < len ; k++ )
                        if(ar[i+k] != pieces[j][k])
                            ok = false;
                    i += len;
                    break;
                }
            if(!ok)
                return false;
        }
        return true;
    }
};