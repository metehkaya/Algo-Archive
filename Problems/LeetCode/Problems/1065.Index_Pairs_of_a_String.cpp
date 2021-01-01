class Solution {
public:
    vector<vector<int>> indexPairs(string s, vector<string>& ar) {
        set<string> words;
        for( int i = 0 ; i < ar.size() ; i++ )
            words.insert(ar[i]);
        int n = s.length();
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> v(2,i);
            string t = "";
            for( int j = i ; j < n ; j++ ) {
                v[1] = j;
                t.push_back(s[j]);
                if(words.find(t) != words.end())
                    ans.push_back(v);
            }
        }
        return ans;
    }
};