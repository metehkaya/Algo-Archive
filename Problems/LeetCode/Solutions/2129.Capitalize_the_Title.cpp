class Solution {
public:
    string getTransform(string& s) {
        int len = s.length();
        for( int i = 0 ; i < len ; i++ )
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        if(len > 2)
            s[0] += 'A' - 'a';
        return s;
    }
    string capitalizeTitle(string s) {
        int n = s.length() , idx = 0;
        string ans = "" , curr = "";
        while(idx < n) {
            if(s[idx] == ' ') {
                ans += getTransform(curr);
                ans.push_back(' ');
                curr = "";
            }
            else
                curr.push_back(s[idx]);
            idx++;
        }
        if(curr != "")
            ans += getTransform(curr);
        return ans;
    }
};
