class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        bool pal[n][n];
        memset(pal,false,sizeof(pal));
        for( int i = 0 ; i < n ; i++ ) {
            pal[i][i] = true;
            int l = i-1 , r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
                pal[l--][r++] = true;
        }
        for( int i = 0 ; i < n-1 ; i++ )
            if(s[i] == s[i+1]) {
                pal[i][i+1] = true;
                int l = i-1 , r = i+2;
                while(l >= 0 && r < n && s[l] == s[r])
                    pal[l--][r++] = true;
            }
        for( int i = 0 ; i <= n-3 ; i++ )
            for( int j = i+2 ; j < n ; j++ )
                if(pal[0][i] && pal[i+1][j-1] && pal[j][n-1])
                    return true;
        return false;
    }
};