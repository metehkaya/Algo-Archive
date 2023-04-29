class Solution {
public:
    int n;
    vector<int> ar;
    int dp[100][100][101];
    int f(int l , int r , int k) {
        if(l > r)
            return 0;
        if(dp[l][r][k] != -1)
            return dp[l][r][k];
        int res = k*k + f(l+1,r,1);
        for( int i = l+1 ; i <= r ; i++ )
            if(ar[l] == ar[i])
                res = max( res , f(l+1,i-1,1) + f(i,r,k+1) );
        return dp[l][r][k] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        ar = boxes;
        n = ar.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,1);
    }
};