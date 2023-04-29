class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,vector<string>> mp;
        for(string s : words) {
            int n = s.length();
            vector<int> v;
            for( int i = 1 ; i < n ; i++ )
                v.push_back(s[i]-s[i-1]);
            mp[v].push_back(s);
        }
        string ans;
        for(auto it : mp) {
            if(it.second.size() == 1)
                ans = it.second[0];
        }
        return ans;
    }
};
