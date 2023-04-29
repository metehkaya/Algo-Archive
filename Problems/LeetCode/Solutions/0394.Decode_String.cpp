class Solution {
public:
    string f(string& s, int& index) {
        string res = "";
        while(index < s.length()) {
            char c = s[index];
            if(c >= '0' && c <= '9') {
                int times = c-'0';
                index++;
                while(s[index] != '[')
                    times = times*10 + s[index++]-'0';
                index++;
                string tmp = f(s,index);
                for( int i = 0 ; i < times ; i++ )
                    res += tmp;
            }
            else if(c == ']') {
                index++;
                return res;
            }
            else
                res.push_back(s[index++]);
        }
        return res;
    }
    string decodeString(string s) {
        int index=0;
        return f(s,index);
    }
};