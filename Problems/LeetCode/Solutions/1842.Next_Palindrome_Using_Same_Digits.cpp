class Solution {
public:
    string nextPalindrome(string s) {
        int n = s.length();
        string t = s.substr(0, n/2);
        if(!next_permutation(begin(t), end(t)))
            return "";
        string ans = t;
        if(n % 2)
            ans.push_back(s[n/2]);
        ans += string(rbegin(t), rend(t));
        return ans;
    }
};
