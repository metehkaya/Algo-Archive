const int mod = (int) 1e9+7;

class Solution {
public:
    int countPalindromes(string s) {
        int n = s.length();
        int cnt_1_pref[10];
        int cnt_2_pref[n][10][10];
        int cnt_1_suff[10];
        int cnt_2_suff[n][10][10];
        memset(cnt_1_pref,0,sizeof(cnt_1_pref));
        memset(cnt_1_suff,0,sizeof(cnt_1_suff));
        memset(cnt_2_pref,0,sizeof(cnt_2_pref));
        memset(cnt_2_suff,0,sizeof(cnt_2_suff));
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'0';
            if(i > 0)
                for( int j = 0 ; j < 10 ; j++ )
                    for( int k = 0 ; k < 10 ; k++ )
                        cnt_2_pref[i][j][k] = cnt_2_pref[i-1][j][k];
            for( int k = 0 ; k < 10 ; k++ )
                cnt_2_pref[i][k][c] = (cnt_2_pref[i][k][c] + cnt_1_pref[k]) % mod;
            cnt_1_pref[c]++;
        }
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int c = s[i]-'0';
            if(i < n-1)
                for( int j = 0 ; j < 10 ; j++ )
                    for( int k = 0 ; k < 10 ; k++ )
                        cnt_2_suff[i][j][k] = cnt_2_suff[i+1][j][k];
            for( int k = 0 ; k < 10 ; k++ )
                cnt_2_suff[i][k][c] = (cnt_2_suff[i][k][c] + cnt_1_suff[k]) % mod;
            cnt_1_suff[c]++;
        }
        int ans = 0;
        for( int i = 2 ; i <= n-3 ; i++ )
            for( int j = 0 ; j < 10 ; j++ )
                for( int k = 0 ; k < 10 ; k++ )
                    ans = (ans + (long long) cnt_2_pref[i-1][j][k] * cnt_2_suff[i+1][j][k]) % mod;
        return ans;
    }
};
