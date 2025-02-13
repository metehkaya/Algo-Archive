class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length() , ans = 0;
        map<int,int> mp;
        for( int l = 0 , r = 0 ; l < n ; l++ ) {
            while(r < n and mp[s[r]] < 2)
                mp[s[r++]]++;
            ans = max(ans,r-l);
            mp[s[l]]--;
        }
        return ans;
    }
};