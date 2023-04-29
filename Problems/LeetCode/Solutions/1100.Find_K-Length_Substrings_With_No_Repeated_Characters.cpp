class Solution {
public:
    bool check(vector<int>& v) {
        for( int i = 0 ; i < 26 ; i++ )
            if(v[i] > 1)
                return false;
        return true;
    }
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.length();
        if(k > n)
            return 0;
        vector<int> cnt(26,0);
        for( int i = 0 ; i < k ; i++ )
            cnt[s[i]-'a']++;
        int ans = check(cnt);
        for( int i = k ; i < n ; i++ ) {
            cnt[s[i]-'a']++;
            cnt[s[i-k]-'a']--;
            ans += check(cnt);
        }
        return ans;
    }
};