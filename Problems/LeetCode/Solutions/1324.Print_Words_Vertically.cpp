class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> allWords;
        string curr = "";
        int len = s.length();
        for( int i = 0 ; i < len ; i++ ) {
            if(s[i] == ' ') {
                allWords.push_back(curr);
                curr = "";
            }
            else
                curr = curr + s[i];
        }
        allWords.push_back(curr);
        int m = allWords.size(), mxSize = 0;
        for( int i = 0 ; i < m ; i++ )
            mxSize = max(mxSize, (int) allWords[i].length());
        vector<string> ans(mxSize,"");
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < (int) allWords[i].length() ; j++ )
                ans[j] = ans[j] + allWords[i][j];
            for( int j = (int) allWords[i].length() ; j < mxSize ; j++ )
                ans[j] = ans[j] + ' ';
        }
        for( int i = 0 ; i < mxSize ; i++ )
            while(ans[i].back() == ' ')
                ans[i].pop_back();
        return ans;
    }
};