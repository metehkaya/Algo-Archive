class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0 , j = 0;
        while(i < n && j < m) {
            if(s[i] != t[j])
                return false;
            int i2 = i;
            while(i2 < n && s[i] == s[i2])
                i2++;
            int j2 = j;
            while(j2 < m && t[j] == t[j2])
                j2++;
            if(j2-j < i2-i)
                return false;
            i = i2;
            j = j2;
        }
        return i == n && j == m;
    }
};