class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        string s = words[0];
        int n = words.size() , len = s.length();
        int x = s[0]-'a' , y = s[len-1]-'a';
        vector<vector<int>> dp(26, vector<int>(26, INT_MAX));
        dp[x][y] = len;
        for( int i = 1 ; i < n ; i++ ) {
            s = words[i];
            len = s.length();
            x = s[0]-'a' , y = s[len-1]-'a';
            vector<vector<int>> dp_next(26, vector<int>(26, INT_MAX));
            for( int a = 0 ; a < 26 ; a++ )
                for( int b = 0 ; b < 26 ; b++ ) {
                    if(dp[a][b] == INT_MAX)
                        continue;
                    dp_next[a][y] = min(dp_next[a][y], dp[a][b]+len-(b==x));
                    dp_next[x][b] = min(dp_next[x][b], dp[a][b]+len-(y==a));
                }
            dp = dp_next;
        }
        int ans = INT_MAX;
        for(auto v : dp)
            for(int val : v)
                ans = min(ans,val);
        return ans;
    }
};
