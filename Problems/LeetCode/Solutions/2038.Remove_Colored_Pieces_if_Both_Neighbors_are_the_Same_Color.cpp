class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.length();
        int cnt[2] = {0,0};
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            cnt[s[i]-'A'] += max(j-i-2,0);
        }
        return cnt[0] > cnt[1];
    }
};
