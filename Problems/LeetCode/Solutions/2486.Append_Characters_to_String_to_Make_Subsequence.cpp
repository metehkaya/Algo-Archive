class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int idx = 0 , i = 0;
        while(i < m) {
            while(idx < n && s[idx] != t[i])
                idx++;
            if(idx < n)
                idx++ , i++;
            else
                break;
        }
        return m-i;
    }
};
