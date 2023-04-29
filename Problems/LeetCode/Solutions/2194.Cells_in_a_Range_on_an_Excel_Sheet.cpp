class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        int tlcol = s[0]-'A';
        int tlrow = s[1]-'0';
        int brcol = s[3]-'A';
        int brrow = s[4]-'0';
        for( int i = tlcol ; i <= brcol ; i++ )
            for( int j = tlrow ; j <= brrow ; j++ ) {
                string s = "";
                s.push_back('A'+i);
                s.push_back('0'+j);
                ans.push_back(s);
            }
        return ans;
    }
};
