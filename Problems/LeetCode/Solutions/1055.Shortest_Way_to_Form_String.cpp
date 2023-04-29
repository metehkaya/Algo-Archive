class Solution {
public:
    int shortestWay(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> next(n, vector<int>(26,-1));
        for( int i = n-1 ; i >= 0 ; i-- ) {
            for( int j = 0 ; j < 26 ; j++ ) {
                if(i == n-1)
                    next[i][j] = -1;
                else
                    next[i][j] = next[i+1][j];
            }
            next[i][s[i]-'a'] = i;
        }
        for( int i = 0 ; i < m ; i++ )
            if(next[0][t[i]-'a'] == -1)
                return -1;
        int ans = 1;
        for( int j = 0 , index = 0 ; j < m ; j++ ) {
            int c = t[j] - 'a';
            if(next[index][c] == -1) {
                ans++;
                index = (next[0][c] + 1) % n;
            }
            else {
                index = (next[index][c] + 1) % n;
                if(index == 0 && j != m-1)
                    ans++;
            }
        }
        return ans;
    }
};