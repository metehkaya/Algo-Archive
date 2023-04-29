class Solution {
public:
    string evaluate(string s, vector<vector<string>>& v) {
        int n = s.length();
        map<string,string> mp;
        for( int i = 0 ; i < v.size() ; i++ )
            mp[v[i][0]] = v[i][1];
        string ans = "";
        map<string,string>::iterator it;
        for( int i = 0 ; i < n ; ) {
            if(s[i] == '(') {
                i++;
                string key = "";
                while(s[i] != ')')
                    key.push_back(s[i++]);
                i++;
                it = mp.find(key);
                if(it == mp.end())
                    ans.push_back('?');
                else
                    ans += it->second;
            }
            else
                ans.push_back(s[i++]);
        }
        return ans;
    }
};