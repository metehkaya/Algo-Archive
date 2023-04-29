class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int i = 0 , n = s.length() , ans = 0;
        while(i < n and s[i] == '1')
            i++;
        while(i < n) {
            int cnt0 = 0 , cnt1 = 0;
            while(i < n and s[i] == '0')
                i++ , cnt0++;
            while(i < n and s[i] == '1')
                i++ , cnt1++;
            ans = max(ans,2*min(cnt0,cnt1));
        }
        return ans;
    }
};
