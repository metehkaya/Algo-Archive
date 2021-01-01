class Solution {
public:
    bool validWordAbbreviation(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0 , j = 0;
        while(i < n && j < m) {
            if(t[j] >= 'a' && t[j] <= 'z') {
                if(s[i] == t[j])
                    i++,j++;
                else
                    return false;
            }
            else {
                int num = 0;
                if(t[j] == '0')
                    return false;
                while(j < m && num <= n-i && t[j] >= '0' && t[j] <= '9') {
                    num *= 10;
                    num += t[j++]-'0';
                }
                if(num > n-i)
                    return false;
                i += num;
            }
        }
        if(i == n && j == m)
            return true;
        return false;
    }
};