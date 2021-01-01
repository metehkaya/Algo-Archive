class Solution {
public:
    string fErr(string& str) {
        string t = "";
        int len = str.length();
        for( int i = 0 ; i < len ; i++ ) {
            if(str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u')
                t.push_back('?');
            else
                t.push_back(str[i]);
        }
        return t;
    }
    string fCap(string& str) {
        string t = "";
        int len = str.length();
        for( int i = 0 ; i < len ; i++ ) {
            if(str[i] >= 'a' && str[i] <= 'z')
                t.push_back(str[i]);
            else
                t.push_back(str[i]+'a'-'A');
        }
        return t;
    }
    vector<string> spellchecker(vector<string>& words, vector<string>& queries) {
        int n = words.size();
        set<string> s;
        map<string,string> cap,err;
        for( int i = 0 ; i < n ; i++ ) {
            string str = words[i];
            string a = fCap(str);
            string b = fErr(a);
            s.insert(str);
            if(cap.find(a) == cap.end())
                cap[a] = str;
            if(err.find(b) == err.end())
                err[b] = str;
        }
        n = queries.size();
        vector<string> ans(n,"");
        for( int i = 0 ; i < n ; i++ ) {
            string str = queries[i];
            string a = fCap(str);
            string b = fErr(a);
            if(s.find(str) != s.end())
                ans[i] = str;
            else if(cap.find(a) != cap.end())
                ans[i] = cap[a];
            else if(err.find(b) != err.end())
                ans[i] = err[b];
        }
        return ans;
    }
};