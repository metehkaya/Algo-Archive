class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        int idx = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        int dot = 0 , dig = 0;
        while(idx < len) {
            if(s[idx] == '.')
                dot++,idx++;
            else if(s[idx] >= '0' && s[idx] <= '9')
                dig++,idx++;
            else
                break;
        }
        if(dig == 0 || dot > 1)
            return false;
        if(idx == len)
            return true;
        if(s[idx] != 'e' && s[idx] != 'E')
            return false;
        idx++;
        if(idx < len && (s[idx] == '+' || s[idx] == '-'))
            idx++;
        dig = 0;
        while(idx < len) {
            if(s[idx] >= '0' && s[idx] <= '9')
                dig++,idx++;
            else
                break;
        }
        if(idx != len || dig == 0)
            return false;
        return true;
    }
};