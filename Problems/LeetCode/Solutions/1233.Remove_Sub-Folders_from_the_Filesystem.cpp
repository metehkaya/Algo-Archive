class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        int n = folders.size();
        unordered_set<string> uos;
        sort(folders.begin() , folders.end());
        for( int i = 0 ; i < n ; i++ ) {
            string s = "";
            bool ok = true;
            int len = folders[i].length();
            for( int j = 0 ; j < len ; j++ ) {
                if(j && folders[i][j] == '/' && uos.find(s) != uos.end()) {
                    ok = false;
                    break;
                }
                s.push_back(folders[i][j]);
            }
            if(ok && uos.find(s) != uos.end())
                ok = false;
            if(ok)
                uos.insert(s);
        }
        vector<string> ans;
        for( auto it = uos.begin() ; it != uos.end() ; it++ )
            ans.push_back((*it));
        return ans;
    }
};