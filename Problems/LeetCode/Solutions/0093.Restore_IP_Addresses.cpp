class Solution {
public:
    void dfs(string& s, string& curr, vector<string>& ans, int pos, int dots) {
        if(pos == s.length()) {
            if(dots == 3)
                ans.push_back(curr);
            return;
        }
        string part = "";
        int len = s.length();
        int maxCh = min(len-pos, 3);
        for( int i = 0 ; i < maxCh ; i++ ) {
            curr.push_back(s[pos+i]);
            part.push_back(s[pos+i]);
            if( i > 0 && part[0] == '0' )
                continue;
            if( i == 2 && part > "255" )
                continue;
            bool addDot = (dots < 3);
            if(dots == 3 && pos+i+1 != s.length())
                continue;
            if(dots < 3 && pos+i+1 >= s.length())
                continue;
            if(addDot)
                curr.push_back('.');
            dfs(s, curr, ans, pos+i+1, dots+addDot);
            if(addDot)
                curr.pop_back();
        }
        for( int i = 0 ; i < maxCh ; i++ )
            curr.pop_back();
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr;
        dfs(s, curr, ans, 0, 0);
        return ans;
    }
};