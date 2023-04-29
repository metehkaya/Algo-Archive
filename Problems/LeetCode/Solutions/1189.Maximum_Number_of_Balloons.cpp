class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        int ans = n;
        ans = min( ans , cnt['a'-'a']/1 );
        ans = min( ans , cnt['b'-'a']/1 );
        ans = min( ans , cnt['n'-'a']/1 );
        ans = min( ans , cnt['l'-'a']/2 );
        ans = min( ans , cnt['o'-'a']/2 );
        return ans;
    }
};