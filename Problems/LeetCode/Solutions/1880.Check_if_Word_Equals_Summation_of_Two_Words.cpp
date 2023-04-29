class Solution {
public:
    int f(string& s) {
        int n = s.length();
        int val = 0;
        for( int i = 0 ; i < n ; i++ )
            val = 10*val + s[i]-'a';
        return val;
    }
    bool isSumEqual(string a, string b, string c) {
        int x = f(a);
        int y = f(b);
        int z = f(c);
        return z == x+y;
    }
};