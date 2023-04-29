class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> ans;
        vector< vector<int> > dp(n+1, vector<int>(n+1,0));
        for( int r = n-1 ; r >= 0 ; r-- )
            for( int l = r-1 ; l >= 0 ; l-- )
                if( text[l] == text[r] ) {
                    dp[l][r] = dp[l+1][r+1] + 1;
                    if(dp[l][r] >= r-l)
                        ans.insert(text.substr(l,r-l));
                }
        return (int) ans.size();
    }
};