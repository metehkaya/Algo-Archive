class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> mp;
        int n = logs.size();
        vector<int> ans(k,0);
        for( int i = 0 ; i < n ; i++ )
            mp[logs[i][0]].insert(logs[i][1]);
        for( auto it : mp ) {
            int freq = it.second.size();
            if(freq >= 1 && freq <= k)
                ans[freq-1]++;
        }
        return ans;
    }
};