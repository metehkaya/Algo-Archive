typedef long long LL;

class Solution {
public:
    LL check(string& word) {
        int len = word.length();
        if(len <= 1)
            return -1;
        if(word[0] != '$')
            return -1;
        LL num = 0;
        for( int i = 1 ; i < len ; i++ ) {
            if('0' <= word[i] && word[i] <= '9')
                num = 10*num + (word[i]-'0');
            else
                return -1;
        }
        return num;
    }
    string discountPrices(string s, int d) {
        s.push_back(' ');
        string ans = "" , word = "";
        for( int i = 0 ; i < s.length() ; i++ ) {
            if(s[i] == ' ') {
                string add;
                LL num = check(word);
                if(num == -1)
                    add = word;
                else {
                    double f = num * (1.0 - d/100.0);
                    std::stringstream stream;
                    stream << std::fixed << std::setprecision(2) << f;
                    add = "$" + stream.str();
                }
                if(!ans.empty())
                    ans.push_back(' ');
                ans += add;
                word = "";
            }
            else
                word.push_back(s[i]);
        }
        return ans;
    }
};
