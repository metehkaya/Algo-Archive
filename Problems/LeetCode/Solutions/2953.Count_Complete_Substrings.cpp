class Solution {
public:
    int countCompleteSubstrings(string s, int k) {
        int n = s.length() , ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(26,0));
        for( int i = 1 ; i <= n ; i++ ) {
            dp[i] = dp[i-1];
            dp[i][s[i-1]-'a']++;
        }
        for( int l = 0 , r = 0 ; l < n ; l = r ) {
            r++;
            while(r < n and abs(s[r]-s[r-1]) <= 2)
                r++;
            for( int i = l ; i < r ; i++ ) {
                int max_times = min((r-i)/k,26);
                for( int t = 1 ; t <= max_times ; t++ ) {
                    int j = i+k*t;
                    bool ok = true;
                    for( int c = 0 ; ok && c < 26 ; c++ ) {
                        int count = dp[j][c] - dp[i][c];
                        if(count != 0 and count != k)
                            ok = false;
                    }
                    ans += ok;
                }
            }
        }
        return ans;
    }
};
