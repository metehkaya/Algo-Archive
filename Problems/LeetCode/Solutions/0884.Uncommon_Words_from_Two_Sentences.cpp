class Solution {
public:
    map<string,int> mp;
    void f(string& s) {
        s.push_back(' ');
        int n = s.length();
        string w = "";
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                mp[w]++;
                w = "";
            }
            else
                w.push_back(s[i]);
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        f(s1);
        f(s2);
        vector<string> ans;
        map<string,int>::iterator it;
        for( it = mp.begin() ; it != mp.end() ; it++ )
            if(it->second == 1)
                ans.push_back(it->first);
        return ans;
    }
};