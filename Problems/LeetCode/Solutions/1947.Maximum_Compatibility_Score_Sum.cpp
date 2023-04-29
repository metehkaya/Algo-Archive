class Solution {
public:
    int n,m,k,ans;
    int ar[8][8];
    bool mark[8];
    void f(int i , int sum) {
        if(i == n) {
            ans = max(ans,sum);
            return;
        }
        f(i+1,sum);
        for( int j = 0 ; j < m ; j++ )
            if(!mark[j]) {
                mark[j] = true;
                f(i+1,sum+ar[i][j]);
                mark[j] = false;
            }
    }
    int maxCompatibilitySum(vector<vector<int>>& x, vector<vector<int>>& y) {
        n = x.size();
        m = y.size();
        k = x[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                for( int l = 0 ; l < k ; l++ )
                    ar[i][j] += (x[i][l] == y[j][l]);
        f(0,0);
        return ans;
    }
};