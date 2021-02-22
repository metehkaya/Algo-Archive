class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = s.length();
        string ans = "";
        int bestLen = 0;
        if(n == 0)
            return ans;
        int nxt[n][26];
        memset(nxt,-1,sizeof(nxt));
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(i < n-1)
                for( int j = 0 ; j < 26 ; j++ )
                    nxt[i][j] = nxt[i+1][j];
            int c = s[i]-'a';
            nxt[i][c] = i;
        }
        int m = d.size();
        for( int i = 0 ; i < m ; i++ ) {
            int len = d[i].length();
            if(len > bestLen || (len == bestLen && d[i] < ans)) {
                int curr = 0;
                for( int j = 0 ; j < len ; j++ ) {
                    if(curr == n) {
                        curr = -1;
                        break;
                    }
                    int c = d[i][j]-'a';
                    if(nxt[curr][c] == -1) {
                        curr = -1;
                        break;
                    }
                    curr = nxt[curr][c]+1;
                }
                if(curr != -1) {
                    ans = d[i];
                    bestLen = len;
                }
            }
        }
        return ans;
    }
};