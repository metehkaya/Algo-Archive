class Solution {
public:
    vector<string> stringMatching(vector<string>& s) {
        int n = s.size();
        vector<string> ans;
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = false;
            for( int j = 0 ; j < n ; j++ )
                if( i != j && s[j].find(s[i]) != string::npos ) {
                    ok = true;
                    break;
                }
            if(ok)
                ans.push_back(s[i]);
        }
        return ans;
    }
};