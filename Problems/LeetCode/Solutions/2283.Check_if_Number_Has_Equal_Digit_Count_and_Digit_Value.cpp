class Solution {
public:
    bool digitCount(string s) {
        vector<int> cnt(10,0);
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'0']++;
        for( int i = 0 ; i < n ; i++ )
            if(cnt[i] != s[i]-'0')
                return false;
        return true;
    }
};
