class Solution {
public:
    void update(int x, int& cnt, int& ans) {
        cnt = (x == 1) ? cnt+1 : 0;
        ans = max(ans, cnt);
    }
    int longestLine(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int m = ar[0].size();
        if(m == 0)
            return 0;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            for( int j = 0 ; j < m ; j++ )
                update(ar[i][j], cnt, ans);
        }
        for( int i = 0 ; i < m ; i++ ) {
            int cnt = 0;
            for( int j = 0 ; j < n ; j++ )
                update(ar[j][i], cnt, ans);
        }
        for( int i2 = 0 ; i2 < n ; i2++ ) {
            int i = i2, j = 0, cnt = 0;
            while(i < n && j < m)
                update(ar[i++][j++], cnt, ans);
        }
        for( int j2 = 0 ; j2 < m ; j2++ ) {
            int j = j2, i = 0, cnt = 0;
            while(i < n && j < m)
                update(ar[i++][j++], cnt, ans);
        }
        for( int i2 = 0 ; i2 < n ; i2++ ) {
            int i = i2, j = m-1, cnt = 0;
            while(i < n && j >= 0)
                update(ar[i++][j--], cnt, ans);
        }
        for( int j2 = 0 ; j2 < m ; j2++ ) {
            int j = j2, i = 0, cnt = 0;
            while(i < n && j >= 0)
                update(ar[i++][j--], cnt, ans);
        }
        return ans;
    }
};