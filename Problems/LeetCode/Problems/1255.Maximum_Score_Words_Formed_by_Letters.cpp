class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& scoreLetter) {
        int n = words.size();
        int N = (1<<n);
        vector<int> score(n,0);
        vector<int> scorebm(N,-1);
        vector<int> letterCnt(26,0);
        vector<vector<int>> cnt(n,vector<int>(26,0));
        vector<vector<int>> cntbm(N,vector<int>(26,0));
        int m = letters.size();
        for( int i = 0 ; i < m ; i++ ) {
            int c = letters[i]-'a';
            letterCnt[c]++;
        }
        for( int i = 0 ; i < n ; i++ ) {
            int len = words[i].length();
            for( int j = 0 ; j < len ; j++ ) {
                int c = words[i][j] - 'a';
                cnt[i][c]++;
                score[i] += scoreLetter[c];
            }
        }
        scorebm[0] = 0;
        for( int bm = 0 ; bm < N ; bm++ )
            if( scorebm[bm] != -1 )
                for( int i = 0 ; i < n ; i++ ) {
                    if( bm & (1<<i) )
                        break;
                    int bm2 = (bm | (1<<i));
                    scorebm[bm2] = scorebm[bm] + score[i];
                    cntbm[bm2] = cntbm[bm];
                    for( int j = 0 ; j < 26 ; j++ ) {
                        cntbm[bm2][j] += cnt[i][j];
                        if(cntbm[bm2][j] > letterCnt[j]) {
                            scorebm[bm2] = -1;
                            break;
                        }
                    }
                }
        int ans = 0;
        for( int i = 0 ; i < N ; i++ )
            ans = max( ans , scorebm[i] );
        return ans;
    }
};