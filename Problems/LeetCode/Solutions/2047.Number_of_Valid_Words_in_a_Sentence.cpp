class Solution {
public:
    bool isa(char c) {
        return c >= 'a' && c <= 'z';
    }
    bool isd(char c) {
        return c >= '0' && c <= '9';
    }
    bool isp(char c) {
        return c == '.' || c == ',' || c == '!';
    }
    vector<string> split(string& s) {
        vector<string> res;
        s.push_back(' ');
        int len = s.length();
        int l = 0;
        while(l < len) {
            int r = s.find_first_of(' ', l);
            if(l < r)
                res.push_back(s.substr(l,r-l));
            l = r+1;
        }
        return res;
    }
    int countValidWords(string sentence) {
        int ans = 0;
        vector<string> res = split(sentence);
        for(string s : res) {
            bool add = true;
            int len = s.length() , cntp = 0;
            for( int i = 0 ; add && i < len ; i++ ) {
                char c = s[i];
                if(isa(c))
                    continue;
                else if(isd(c))
                    add = false;
                else if(isp(c)) {
                    if(i != len-1)
                        add = false;
                }
                else if(c == '-') {
                    if(cntp > 0 || i == 0 || i == len-1 || !isa(s[i-1]) || !isa(s[i+1]))
                        add = false;
                    else
                        cntp++;
                }
                else
                    assert(false);
            }
            ans += add;
        }
        return ans;
    }
};
