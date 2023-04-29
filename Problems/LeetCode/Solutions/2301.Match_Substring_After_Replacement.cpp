class Solution {
public:
    bool ar[256][256];
    bool matchReplacement(string s, string t, vector<vector<char>>& mappings) {
        int n = s.length();
        int m = t.length();
        memset(ar,false,sizeof(ar));
        for( int i = 0 ; i < mappings.size() ; i++ ) {
            int x = (int) mappings[i][0];
            int y = (int) mappings[i][1];
            ar[x][y] = true;
        }
        for( int i = 0 ; i < 256 ; i++ )
            ar[i][i] = true;
        for( int i = 0 ; i <= n-m ; i++ ) {
            bool ok = true;
            for( int j = 0 ; j < m ; j++ )
                if(!ar[(int)t[j]][(int)s[i+j]]) {
                    ok = false;
                    break;
                }
            if(ok)
                return true;
        }
        return false;
    }
};
