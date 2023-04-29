class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.length();
        vector<bool> mark(26,false);
        for( int i = 0 ; i < n ; i++ )
            mark[s[i]-'a'] = true;
        for( int i = 0 ; i < 26 ; i++ )
            if(!mark[i])
                return false;
        return true;
    }
};