class Solution {
public:
    vector<string> getFolderNames(vector<string>& ar) {
        int n = ar.size();
        vector<string> ans;
        unordered_set<string> s;
        unordered_map<string,int> cnt;
        for( int i = 0 ; i < n ; i++ ) {
            string str = ar[i];
            if(s.find(str) == s.end()) {
                s.insert(str);
                ans.push_back(str);
            }
            else {
                if(cnt.find(str) == cnt.end())
                    cnt[str] = 1;
                while(s.find(str+"("+to_string(cnt[str])+")") != s.end())
                    cnt[str]++;
                string t = str + "(" + to_string(cnt[str]) + ")";
                s.insert(t);
                ans.push_back(t);
            }
        }
        return ans;
    }
};