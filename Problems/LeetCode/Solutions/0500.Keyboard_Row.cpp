class Solution {
public:
    int mask[26];
    void fmask(string s , int bmask) {
        int len = s.length();
        for( int i = 0 ; i < len ; i++ ) {
            int c = s[i]-'a';
            mask[c] = bmask;
        }
    }
    vector<string> findWords(vector<string>& ar) {
        fmask("qwertyuiop",1);
        fmask("asdfghjkl",2);
        fmask("zxcvbnm",4);
        int n = ar.size();
        vector<string> ans;
        for( int i = 0 ; i < n ; i++ ) {
            string s = ar[i];
            int len = s.length();
            int bmask = 0;
            for( int j = 0 ; j < len ; j++ ) {
                int c = (s[j] <= 'Z') ? s[j]-'A' : s[j]-'a';
                bmask |= mask[c];
            }
            if(bmask == 1 || bmask == 2 || bmask == 4)
                ans.push_back(s);
        }
        return ans;
    }
};