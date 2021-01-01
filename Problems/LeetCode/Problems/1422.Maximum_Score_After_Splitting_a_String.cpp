class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> cnt(n,0);
        cnt[0] = (s[0] == '0');
        for( int i = 1 ; i < n ; i++ )
            cnt[i] = cnt[i-1] + (s[i] == '0');
        int ans = 0;
        int cntAll0 = cnt[n-1];
        int cntAll1 = n - cntAll0;
        for( int i = 0 ; i < n-1 ; i++ ) {
            int cnt0 = cnt[i];
            int cnt1 = cntAll1 - (i+1 - cnt0);
            ans = max( ans , cnt0 + cnt1 );
        }
        return ans;
    }
};