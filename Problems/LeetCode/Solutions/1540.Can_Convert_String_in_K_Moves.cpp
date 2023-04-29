class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.length() , m = t.length();
        if(n != m)
            return false;
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ ) {
            int diff = (t[i] - s[i] + 26) % 26;
            if(diff)
                cnt[diff]++;
        }
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i] && (i+(cnt[i]-1)*26) > k)
                return false;
        return true;
    }
};