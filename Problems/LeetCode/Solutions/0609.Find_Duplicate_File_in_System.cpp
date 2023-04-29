class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& s) {
        int n = s.size();
        map<string,vector<string>> mp;
        for( int i = 0 ; i < n ; i++ ) {
            string t = s[i];
            t.push_back(' ');
            int len = t.length();
            string dir = "";
            string word = "";
            for( int j = 0 ; j < len ; j++ ) {
                char c = t[j];
                if(c == ' ') {
                    if(dir == "")
                        dir = word;
                    else {
                        int len2 = word.length();
                        int idx = len2-2;
                        while(word[idx] != '(')
                            idx--;
                        idx++;
                        string content = word.substr(idx,(len2-1)-idx);
                        mp[content].push_back(dir+"/"+word.substr(0,idx-1));
                    }
                    word = "";
                }
                else
                    word.push_back(c);
            }
        }
        vector<vector<string>> ans;
        map<string,vector<string>>::iterator it;
        for( it = mp.begin() ; it != mp.end() ; it++ ) {
            vector<string> add = (*it).second;
            if(add.size() > 1)
                ans.push_back(add);
        }
        return ans;
    }
};