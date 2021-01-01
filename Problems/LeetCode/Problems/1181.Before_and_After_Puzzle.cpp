class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> words(n);
        for( int i = 0 ; i < n ; i++ ) {
            string t = s[i];
            string w = "";
            int len = t.length();
            for( int j = 0 ; j < len ; j++ ) {
                if(t[j] == ' ')
                    words[i].push_back(w) , w = "";
                else
                    w.push_back(t[j]);
            }
            words[i].push_back(w);
        }
        set<string> res;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(i != j && words[i].back() == words[j].front()) {
                    string t = s[i];
                    for( int k = 1 ; k < words[j].size() ; k++ )
                        t += " " + words[j][k];
                    res.insert(t);
                }
        vector<string> ans;
        ans.insert(ans.end() , res.begin() , res.end());
        return ans;
    }
};