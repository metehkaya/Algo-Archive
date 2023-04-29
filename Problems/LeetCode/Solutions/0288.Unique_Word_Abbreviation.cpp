class ValidWordAbbr {
public:
    map<string,set<string>> mp;
    ValidWordAbbr(vector<string>& dictionary) {
        for(string s : dictionary) {
            int n = s.length();
            string t = s[0] + to_string(n) + s[n-1];
            mp[t].insert(s);
        }
    }
    bool isUnique(string s) {
        int n = s.length();
        string t = s[0] + to_string(n) + s[n-1];
        return mp[t].count(s) == mp[t].size();
    }
};
