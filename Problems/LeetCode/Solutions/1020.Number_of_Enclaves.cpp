class Solution {
public:
    const int DIR[4][2] = {{0,-1},{-1,0},{0,+1},{+1,0}};
    void dfs(int i , int j , int& cnt , bool& add , int n , int m , vector<vector<int>>& ar) {
        cnt++;
        if(i == 0 or i == n-1 or j == 0 or j == m-1)
            add = false;
        ar[i][j] = 0;
        for( int k = 0 ; k < 4 ; k++ ) {
            int i2 = i + DIR[k][0];
            int j2 = j + DIR[k][1];
            if(i2 < 0 or i2 == n or j2 < 0 or j2 == m)
                continue;
            if(ar[i2][j2] == 0)
                continue;
            dfs(i2,j2,cnt,add,n,m,ar);
        }
    }
    int numEnclaves(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    int cnt = 0;
                    bool add = true;
                    dfs(i,j,cnt,add,n,m,ar);
                    ans += add*cnt;
                }
        return ans;
    }
};