class Solution {
public:
    string largestMerge(string s, string t) {
        string ans = "";
        int i = 0 , j = 0;
        int n = s.length();
        int m = t.length();
        while(i < n && j < m) {
            if(s.substr(i) > t.substr(j))
                ans.push_back(s[i++]);
            else
                ans.push_back(t[j++]);
        }
        ans += s.substr(i);
        ans += t.substr(j);
        return ans;
    }
};