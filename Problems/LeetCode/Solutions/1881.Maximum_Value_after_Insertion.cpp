class Solution {
public:
    string maxValue(string s, int x) {
        char c = '0'+x;
        int n = s.length();
        if(s[0] != '-') {
            for( int i = 0 ; i < n ; i++ )
                if(c > s[i]) {
                    s.insert(s.begin()+i,c);
                    return s;
                }
        }
        else {
            for( int i = 1 ; i < n ; i++ )
                if(c < s[i]) {
                    s.insert(s.begin()+i,c);
                    return s;
                }
        }
        s.push_back(c);
        return s;
    }
};