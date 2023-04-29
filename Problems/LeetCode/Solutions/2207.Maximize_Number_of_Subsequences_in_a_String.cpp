class Solution {
public:
    int cnt[26];
    int total[26];
    long long maximumSubsequenceCount(string s, string t) {
        int n = s.length();
        long long curr = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == t[1])
                curr += total[t[0]-'a'];
            total[s[i]-'a']++;
        }
        long long ans = curr;
        for( int i = 0 ; i <= n ; i++ ) {
            int cntl = cnt[t[0]-'a'];
            int cntr = total[t[1]-'a'] - cnt[t[1]-'a'];
            if(t[0] == t[1])
                ans = max(ans,curr+cntl+cntr);
            else
                ans = max(ans,curr+max(cntl,cntr));
            if(i < n)
                cnt[s[i]-'a']++;
        }
        return ans;
    }
};
