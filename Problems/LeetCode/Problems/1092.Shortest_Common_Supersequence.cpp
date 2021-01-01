class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp, vector<vector<int>>& way) {
        if(i == s.length())
            return t.length()-j;
        if(j == t.length())
            return s.length()-i;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = s.length() + t.length() + 5;
        if(s[i] == t[j]) {
            dp[i][j] = f(i+1,j+1,s,t,dp,way) + 1;
            way[i][j] = 0;
        }
        int val;
        val = f(i+1,j,s,t,dp,way) + 1;
        if(val < dp[i][j]) {
            dp[i][j] = val;
            way[i][j] = 1;
        }
        val = f(i,j+1,s,t,dp,way) + 1;
        if(val < dp[i][j]) {
            dp[i][j] = val;
            way[i][j] = 2;
        }
        return dp[i][j];
    }
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> way(n,vector<int>(m,-1));
        f(0,0,s,t,dp,way);
        int i=0,j=0;
        string ans = "";
        while(i < n && j < m) {
            if(way[i][j] == 0)
                ans.push_back(s[i++]),j++;
            else if(way[i][j] == 1)
                ans.push_back(s[i++]);
            else
                ans.push_back(t[j++]);
        }
        while(i < n)
            ans.push_back(s[i++]);
        while(j < m)
            ans.push_back(t[j++]);
        return ans;
    }
};