class Solution {
public:
    bool checkString(string s) {
        int idx = 0 , n = s.length();
        while(idx < n && s[idx] == 'a')
            idx++;
        while(idx < n && s[idx] == 'b')
            idx++;
        return idx == n;
    }
};
