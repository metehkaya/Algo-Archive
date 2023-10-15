class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        vector<int> mult_l(n*m,1) , mult_r(n*m,1);
        for( int i = 0 ; i < n*m ; i++ ) {
            int r = i/m , c = i%m;
            if(i-1 >= 0)
                mult_l[i] = mult_l[i-1];
            int val = v[r][c] % mod;
            mult_l[i] = mult_l[i]*val % mod;
        }
        for( int i = n*m-1 ; i >= 0 ; i-- ) {
            int r = i/m , c = i%m;
            if(i+1 < n*m)
                mult_r[i] = mult_r[i+1];
            int val = v[r][c] % mod;
            mult_r[i] = mult_r[i]*val % mod;
        }
        vector<vector<int>> ans(n,vector<int>(m,1));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int k = m*i+j;
                if(k-1 >= 0)
                    ans[i][j] = ans[i][j] * mult_l[k-1] % mod;
                if(k+1 < n*m)
                    ans[i][j] = ans[i][j] * mult_r[k+1] % mod;
            }
        return ans;
    }
};
