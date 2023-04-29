class Solution {
public:
    static const int maxc = 26;
    static const int maxn = 50000;
    int nxt[maxn][maxc];
    int numMatchingSubseq(string s, vector<string>& ar) {
        int n = s.length();
        for( int i = 0 ; i < maxc ; i++ )
            nxt[n-1][i] = -1;
        nxt[n-1][s[n-1]-'a'] = n-1;
        for( int i = n-2 ; i >= 0 ; i-- ) {
            for( int j = 0 ; j < maxc ; j++ )
                nxt[i][j] = nxt[i+1][j];
            nxt[i][s[i]-'a'] = i;
        }
        int ans = 0;
        int m = ar.size();
        for( int i = 0 ; i < m ; i++ ) {
            string t = ar[i];
            int len = t.length();
            int idx = 0 , curr = 0;
            while(idx < len && curr < n) {
                int c = t[idx]-'a';
                if(nxt[curr][c] == -1)
                    break;
                idx++;
                curr = nxt[curr][c] + 1;
            }
            ans += (idx == len);
        }
        return ans;
    }
};