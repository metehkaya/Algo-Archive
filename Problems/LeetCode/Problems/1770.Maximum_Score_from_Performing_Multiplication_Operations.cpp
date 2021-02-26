class Solution {
public:
    int n,m;
    int dp[1001][1001];
    vector<int> ar,mult;
    int f(int l , int r) {
        if(l+r == m)
            return 0;
        if(dp[l][r] != INT_MIN)
            return dp[l][r];
        int idx = l+r;
        dp[l][r] = max(dp[l][r],mult[idx]*ar[l]+f(l+1,r));
        dp[l][r] = max(dp[l][r],mult[idx]*ar[n-1-r]+f(l,r+1));
        return dp[l][r];
    }
    int maximumScore(vector<int>& ar, vector<int>& mult) {
        n = ar.size();
        m = mult.size();
        this->ar = ar;
        this->mult = mult;
        for( int i = 0 ; i <= m ; i++ )
            for( int j = 0 ; j <= m ; j++ )
                dp[i][j] = INT_MIN;
        return f(0,0);
    }
};