class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int diff = 0 , ans = 0;
        vector<int> cnt(256,0);
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n) {
                int newDiff = diff + (cnt[s[j]] == 0);
                if(newDiff > 2)
                    break;
                cnt[s[j++]]++;
                diff = newDiff;
            }
            ans = max(ans,j-i);
            if(--cnt[s[i]] == 0)
                diff--;
        }
        return ans;
    }
};