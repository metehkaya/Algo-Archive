class Solution {
public:
    int cnt[26][26];
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        for( int i = 0 ; i < n ; i++ ) {
            int a = words[i][0]-'a';
            int b = words[i][1]-'a';
            cnt[a][b]++;
        }
        int ans = 0;
        for( int i = 0 ; i < 26 ; i++ )
            for( int j = i+1 ; j < 26 ; j++ )
                ans += 4*min(cnt[i][j],cnt[j][i]);
        bool isOdd = false;
        for( int i = 0 ; i < 26 ; i++ ) {
            if(cnt[i][i] % 2)
                isOdd = true;
            ans += 4*(cnt[i][i]/2);
        }
        if(isOdd)
            ans += 2;
        return ans;
    }
};
