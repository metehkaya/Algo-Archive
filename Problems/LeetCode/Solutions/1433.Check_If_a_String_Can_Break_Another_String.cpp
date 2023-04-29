class Solution {
public:
    void change(string& s) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        s = "";
        for( int i = 0 ; i < 26 ; i++ ) {
            char c = 'a' + i;
            for( int j = 0 ; j < cnt[i] ; j++ )
                s.push_back(c);
        }
    }
    bool check(string& s, string& t) {
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            if( s[i] > t[i] )
                return false;
        return true;
    }
    bool checkIfCanBreak(string s, string t) {
        change(s);
        change(t);
        if(check(s,t))
            return true;
        swap(s,t);
        return check(s,t);
    }
};