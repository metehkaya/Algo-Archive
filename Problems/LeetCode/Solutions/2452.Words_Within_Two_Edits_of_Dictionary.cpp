class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string s : queries) {
            int n = s.length();
            for(string t : dictionary) {
                if(n != t.length())
                    continue;
                int diff = 0;
                for( int i = 0 ; i < n ; i++ )
                    diff += s[i] != t[i];
                if(diff <= 2) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
