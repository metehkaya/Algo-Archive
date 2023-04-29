class Solution {
public:
    vector<int> getE(string& s) {
        vector<int> cnt(26,0);
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a'] = 1;
        return cnt;
    }
    vector<int> getF(string& s) {
        vector<int> cnt(26,0);
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        sort(cnt.begin(),cnt.end());
        return cnt;
    }
    bool closeStrings(string s, string t) {
        vector<int> s1 = getF(s);
        vector<int> t1 = getF(t);
        vector<int> s2 = getE(s);
        vector<int> t2 = getE(t);
        for( int i = 0 ; i < 26 ; i++ )
            if(s1[i] != t1[i] || s2[i] != t2[i])
                return false;
        return true;
    }
};