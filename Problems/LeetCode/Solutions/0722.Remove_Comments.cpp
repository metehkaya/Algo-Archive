class Solution {
public:
    vector<string> removeComments(vector<string>& str) {
        vector<string> ans;
        int n = str.size();
        bool blockComment = false;
        string res = "";
        for( int i = 0 ; i < n ; i++ ) {
            int len = str[i].length();
            for( int j = 0 ; j < len ; j++ ) {
                if(!blockComment) {
                    if(j+2 <= len && str[i][j]=='/' && str[i][j+1]=='*')
                        j++, blockComment = true;
                    else if(j+2 <= len && str[i][j]=='/' && str[i][j+1]=='/')
                        break;
                    else
                        res.push_back(str[i][j]);
                }
                else {
                    if(j+2 <= len && str[i][j]=='*' && str[i][j+1]=='/')
                        j++, blockComment = false;
                }
            }
            if(!blockComment && res != "")
                ans.push_back(res), res="";
        }
        return ans;
    }
};