class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& s) {
        map<vector<int>,vector<string>> hashh;
        for( int i = 0 ; i < s.size() ; i++ ) {
            vector<int> v;
            for( int j = 0 ; j < s[i].length() - 1 ; j++ ) {
                int diff = ( s[i][j+1] - s[i][j] + 26 ) % 26;
                v.push_back(diff);
            }
            hashh[v].push_back(s[i]);
        }
        vector<vector<string>> ans;
        map<vector<int>,vector<string>>:: iterator mit = hashh.begin();
        while(mit != hashh.end()) {
            ans.push_back(mit->second);
            mit++;
        }
        return ans;
    }
};