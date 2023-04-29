class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if(k == 0)
            return 0;
        int ans = 0;
        vector<int> cnt(256,0);
        for( int i = 0 , j = 0 , total = 0 ; i < n ; i++ ) {
            while(j < n && (total + (cnt[s[j]] == 0)) <= k) {
                total += (cnt[s[j]] == 0);
                cnt[s[j++]]++;
            }
            ans = max(ans,j-i);
            total -= (--cnt[s[i]] == 0);
        }
        return ans;
    }
};