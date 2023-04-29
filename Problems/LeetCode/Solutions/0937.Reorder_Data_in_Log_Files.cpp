class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans,logL,logD;
        int n = logs.size();
        for( int i = 0 ; i < n ; i++ ) {
            char c = logs[i].back();
            if(c >= '0' && c <= '9')
                logD.push_back(logs[i]);
            else
                logL.push_back(logs[i]);
        }
        sort(logL.begin() , logL.end() , []( string s , string t ) {
            string ss = s.substr(s.find(" "));
            string tt = t.substr(t.find(" "));
            if(ss != tt)
                return ss < tt;
            return s < t;
        });
        ans = logL;
        ans.insert(ans.end() , logD.begin() , logD.end());
        return ans;
    }
};