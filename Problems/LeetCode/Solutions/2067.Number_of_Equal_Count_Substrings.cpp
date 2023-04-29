class Solution {
public:
    int equalCountSubstrings(string s, int k) {
        int n = s.length();
        vector<vector<int>> sum(n+1,vector<int>(26,0));
        for( int i = 0 ; i < n ; i++ ) {
            sum[i+1] = sum[i];
            sum[i+1][s[i]-'a']++;
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int t = 1 ; t <= 26 and i+t*k <= n ; t++ ) {
                int j = i+t*k;
                bool ok = true;
                for( int c = 0 ; ok and c < 26 ; c++ ) {
                    int diff = sum[j][c]-sum[i][c];
                    if(diff != 0 and diff != k)
                        ok = false;
                }
                ans += ok;
            }
        return ans;
    }
};
