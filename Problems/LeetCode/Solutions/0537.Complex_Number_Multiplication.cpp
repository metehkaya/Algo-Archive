#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int findPlus(string s) {
        int idx = -1;
        for( int i = 0 ; i < s.length() ; i++ )
            if(s[i] == '+')
                idx = i;
        return idx;
    }
    string int2str(int num) {
        if(num == 0)
            return "0";
        string s = "";
        if(num < 0) {
            s.push_back('-');
            num = abs(num);
        }
        string s2 = "";
        while(num) {
            s2.push_back('0'+(num%10));
            num /= 10;
        }
        reverse(s2.begin(),s2.end());
        return s+s2;
    }
    int str2int(string s) {
        int num = 0;
        bool neg = false;
        for( int i = 0 ; i < s.length() ; i++ ) {
            if(s[i] == '-')
                neg = true;
            else
                num = 10*num + (s[i]-'0');
        }
        if(neg)
            num = -num;
        return num;
    }
    pi str2im(string s) {
        int idx = findPlus(s);
        int len = s.length();
        pi res;
        res.fi = str2int(s.substr(0,idx));
        res.se = str2int(s.substr(idx+1,len-idx-2));
        return res;
    }
    string complexNumberMultiply(string s1, string s2) {
        pi a = str2im(s1);
        pi b = str2im(s2);
        pi res = pi(a.fi*b.fi - a.se*b.se , a.fi*b.se + a.se*b.fi);
        string s_1 = int2str(res.fi);
        string s_2 = int2str(res.se);
        return s_1 + "+" + s_2 + "i";
    }
};