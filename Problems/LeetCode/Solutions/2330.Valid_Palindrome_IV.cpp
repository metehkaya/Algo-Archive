class Solution {
public:
    bool makePalindrome(string s) {
        int n = s.length() , cnt = 0;
        int l = 0 , r = n-1;
        while(l < r) {
            cnt += (s[l] != s[r]);
            l++ , r--;
        }
        return cnt <= 2;
    }
};
