class Solution {
public:
    int n,m,l;
    string word;
    bool check(string& s) {
        int len = s.length();
        if(l != len)
            return false;
        bool ok = true;
        for( int i = 0 ; i < l ; i++ )
            if(s[i] != ' ' && s[i] != word[i]) {
                ok = false;
                break;
            }
        if(ok)
            return true;
        ok = true;
        reverse(s.begin(),s.end());
        for( int i = 0 ; i < l ; i++ )
            if(s[i] != ' ' && s[i] != word[i])
                return false;
        return true;
    }
    bool placeWordInCrossword(vector<vector<char>>& ar, string word) {
        n = ar.size();
        m = ar[0].size();
        l = word.length();
        this->word = word;
        for( int i = 0 ; i < n ; i++ ) {
            string s = "";
            for( int j = 0 ; j < m ; j++ ) {
                if(ar[i][j] == '#') {
                    if(check(s))
                        return true;
                    s = "";
                }
                else
                    s.push_back(ar[i][j]);
            }
            if(check(s))
                return true;
        }
        for( int j = 0 ; j < m ; j++ ) {
            string s = "";
            for( int i = 0 ; i < n ; i++ ) {
                if(ar[i][j] == '#') {
                    if(check(s))
                        return true;
                    s = "";
                }
                else
                    s.push_back(ar[i][j]);
            }
            if(check(s))
                return true;
        }
        return false;
    }
};
