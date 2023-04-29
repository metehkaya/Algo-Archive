class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string t) {
        int n = words.size();
        int len = t.length();
        vector<string> ans;
        for( int i = 0 ; i < n ; i++ ) {
            string s = words[i];
            vector<int> to(26,-1);
            vector<bool> used(26,false);
            bool ok = true;
            for( int j = 0 ; j < len ; j++ ) {
                int c1 = s[j]-'a';
                int c2 = t[j]-'a';
                if(used[c2] && to[c1] != c2) {
                    ok = false;
                    break;
                }
                if(!used[c2] && to[c1] != -1 && to[c1] != c2) {
                    ok = false;
                    break;
                }
                to[c1] = c2;
                used[c2] = true;
            }
            if(ok)
                ans.push_back(s);
        }
        return ans;
    }
};