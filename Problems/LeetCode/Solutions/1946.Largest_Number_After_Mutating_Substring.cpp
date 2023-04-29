class Solution {
public:
    string maximumNumber(string s, vector<int>& to) {
        int n = s.length();
        string t = s;
        int i = 0;
        for( i = 0 ; i < n ; i++ )
            if(s[i]-'0' < to[s[i]-'0'])
                break;
        while(i < n) {
            char c = '0'+to[s[i]-'0'];
            if(c < s[i])
                break;
            t[i++] = c;
        }
        return t;
    }
};