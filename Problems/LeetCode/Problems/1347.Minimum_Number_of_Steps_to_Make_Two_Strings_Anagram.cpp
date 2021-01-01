class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ ) {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        int sum = 0;
        for( int i = 0 ; i < 26 ; i++ )
            sum += abs(cnt[i]);
        return sum/2;
    }
};