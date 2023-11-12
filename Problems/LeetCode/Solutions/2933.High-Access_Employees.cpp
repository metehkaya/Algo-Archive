class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>> mp;
        for(auto v : access_times) {
            string s = v[0];
            int val = 60*stoi(v[1].substr(0,2)) + stoi(v[1].substr(2,2));
            mp[s].push_back(val);
        }
        vector<string> ans;
        for(auto it : mp) {
            string s = it.first;
            vector<int> v = it.second;
            sort(v.begin(),v.end());
            int n = v.size();
            for( int i = 0 ; i <= n-3 ; i++ )
                if(v[i+2]-v[i] < 60) {
                    ans.push_back(s);
                    break;
                }
        }
        return ans;
    }
};
