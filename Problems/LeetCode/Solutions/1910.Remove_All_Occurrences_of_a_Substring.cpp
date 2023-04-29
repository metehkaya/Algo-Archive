class Solution {
public:
    string removeOccurrences(string s, string t) {
        string curr = "";
        int n = s.length();
        int m = t.length();
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            curr.push_back(c);
            int len = curr.length();
            if(len >= m && curr.substr(len-m,m) == t)
                curr = curr.substr(0,len-m);
        }
        return curr;
    }
};