class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int n = s.length();
        vector<string> ans;
        for( int i = 0 ; i < n-1 ; i++ )
            if(s[i] == '+' && s[i+1] == '+') {
                string t = s.substr(0,i) + "--" + s.substr(i+2,n-i-2);
                ans.push_back(t);
            }
        return ans;
    }
};