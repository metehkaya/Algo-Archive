class Solution {
public:
    void f(string& s , int mx) {
        if(s[0] == '?' && s[1] == '?')
            s[0] = '0' + (mx/10) , s[1] = '0' + (mx%10);
        else if(s[0] == '?') {
            if(s[1]-'0' <= mx%10)
                s[0] = '0' + mx/10;
            else
                s[0] = '0' + (mx/10-1);
        }
        else if(s[1] == '?') {
            if(s[0]-'0' < mx/10)
                s[1] = '9';
            else
                s[1] = '0' + mx%10;
        }
    }
    string maximumTime(string s) {
        string hour = s.substr(0,2);
        string minute = s.substr(3,2);
        f(hour,23);
        f(minute,59);
        return hour + ":" + minute;
    }
};