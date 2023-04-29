class Solution {
public:
    bool isPrefixString(string s, vector<string>& ar) {
        int n = ar.size();
        string t = "";
        for( int i = 0 ; i < n ; i++ ) {
            t += ar[i];
            if(s == t)
                return true;
        }
        return false;
    }
};