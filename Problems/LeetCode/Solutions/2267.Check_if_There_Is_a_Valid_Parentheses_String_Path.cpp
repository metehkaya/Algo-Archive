class Solution {
public:
    int n,m;
    vector<vector<char>> ar;
    int dp[100][100][200];
    int getval(int r , int c) {
        return ar[r][c] == '(' ? 1 : -1;
    }
    bool f(int r , int c , int val) {
        if(r < 0 || r >= n || c < 0 || c >= m)
            return false;
        val += getval(r,c);
        if(val < 0)
            return false;
        if(r == n-1 && c == m-1)
            return (val == 0);
        if(dp[r][c][val] != -1)
            return dp[r][c][val];
        return dp[r][c][val] = f(r,c+1,val) or f(r+1,c,val);
    }
    bool hasValidPath(vector<vector<char>>& ar) {
        this->ar = ar;
        n = ar.size();
        m = ar[0].size();
        if((n+m)%2 == 0)
            return false;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0);
    }
};
