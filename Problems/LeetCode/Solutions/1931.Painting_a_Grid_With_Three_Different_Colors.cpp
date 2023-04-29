class Solution {
public:
    int n,m,k,s;
    vector<int> v;
    int dp[1000][243];
    bool var[243][243];
    vector<int> Col[243];
    const int mod = (int) 1e9+7;
    void f(int id , int bmask , int last , vector<int>& col) {
        if(id == m) {
            v.push_back(bmask);
            Col[bmask] = col;
            return;
        }
        for( int i = 0 ; i < 3 ; i++ )
            if(i != last) {
                col[id] = i;
                int bmask2 = 3*bmask+i;
                f(id+1,bmask2,i,col);
            }
    }
    int colorTheGrid(int m, int n) {
        this->n = n;
        this->m = m;
        k = 1;
        for( int i = 0 ; i < m ; i++ )
            k *= 3;
        vector<int> col(m);
        f(0,0,-1,col);
        s = v.size();
        for( int i1 = 0 ; i1 < s ; i1++ )
            for( int i2 = 0 ; i2 < s ; i2++ ) {
                int b1 = v[i1];
                int b2 = v[i2];
                bool ok = true;
                for( int i = 0 ; i < m ; i++ )
                    if(Col[b1][i] == Col[b2][i])
                        ok = false;
                var[b1][b2] = ok;
            }
        for( int i = 0 ; i < s ; i++ )
            dp[0][v[i]] = 1;
        for( int i = 1 ; i < n ; i++ )
            for( int b1 = 0 ; b1 < k ; b1++ )
                for( int b0 = 0 ; b0 < k ; b0++ )
                    if(var[b0][b1])
                        dp[i][b1] = (dp[i][b1] + dp[i-1][b0]) % mod;
        int ans = 0;
        for( int i = 0 ; i < k ; i++ )
            ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
};