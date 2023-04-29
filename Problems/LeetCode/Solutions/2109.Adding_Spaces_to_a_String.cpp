class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size() , idx = 0 , len = s.length();
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            while(idx < spaces[i])
                ans.push_back(s[idx++]);
            ans.push_back(' ');
        }
        ans += s.substr(idx,len-idx);
        return ans;
    }
};
