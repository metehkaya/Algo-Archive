class Solution {
public:
    bool checkInclusion(string t, string s) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> sum(n+1, vector<int>(26,0));
        for( int i = 1 ; i <= n ; i++ ) {
            int c = s[i-1] - 'a';
            for( int j = 0 ; j < 26 ; j++ )
                sum[i][j] = sum[i-1][j] + (j == c);
        }
        vector<int> cnt(26, 0);
        for( int i = 0 ; i < m ; i++ )
            cnt[t[i]-'a']++;
        for( int i = 0 ; i <= n-m ; i++ ) {
            bool isSame = true;
            for( int j = 0 ; j < 26 ; j++ )
                if( sum[i+m][j] - sum[i][j] != cnt[j] )
                    isSame = false;
            if(isSame)
                return true;
        }
        return false;
    }
};