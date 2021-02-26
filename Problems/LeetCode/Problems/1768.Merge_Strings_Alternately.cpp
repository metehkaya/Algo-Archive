class Solution {
public:
    string mergeAlternately(string s, string t) {
        int n = s.length();
        int m = t.length();
        int mn = min(n,m);
        string ans = "";
        for( int i = 0 ; i < mn ; i++ ) {
            ans.push_back(s[i]);
            ans.push_back(t[i]);
        }
        for( int i = mn ; i < n ; i++ )
            ans.push_back(s[i]);
        for( int i = mn ; i < m ; i++ )
            ans.push_back(t[i]);
        return ans;
    }
};