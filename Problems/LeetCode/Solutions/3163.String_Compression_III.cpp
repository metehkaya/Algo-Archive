class Solution {
public:
    string compressedString(string s) {
        string ans = "";
        int n = s.length();
        int l = 0 , r = 0;
        while(l < n) {
            while(r < n and r < l+9 and s[l] == s[r])
                r++;
            ans.push_back('0'+(r-l));
            ans.push_back(s[l]);
            l = r;
        }
        return ans;
    }
};