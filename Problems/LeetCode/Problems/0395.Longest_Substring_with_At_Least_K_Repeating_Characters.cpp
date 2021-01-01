class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int cnt[n+1][26];
        memset(cnt,0,sizeof(cnt));
        vector<int> idx[26];
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < 26 ; j++ )
                cnt[i+1][j] = cnt[i][j];
            int c = s[i]-'a';
            cnt[i+1][c]++;
            idx[c].push_back(i);
        }
        int ans = 0;
        for( int l = 0 ; l < n ; l++ ) {
            int r = n;
            bool cont;
            do {
                cont = false;
                for( int i = 0 ; i < 26 ; i++ ) {
                    int diff = cnt[r][i] - cnt[l][i];
                    if(diff > 0 && diff < k) {
                        cont = true;
                        r = idx[i][cnt[l][i]];
                    }
                }
            }while(cont);
            ans = max(ans,r-l);
        }
        return ans;
    }
};