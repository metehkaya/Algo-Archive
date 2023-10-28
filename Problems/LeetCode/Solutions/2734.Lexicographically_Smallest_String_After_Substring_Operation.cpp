class Solution {
public:
    string smallestString(string s) {
        int n = s.length() , idx = 0;
        while(idx < n and s[idx] == 'a')
            idx++;
        if(idx == n) {
            s[n-1] = 'z';
            return s;
        }
        while(idx < n and s[idx] != 'a')
            s[idx++]--;
        return s;
    }
};
