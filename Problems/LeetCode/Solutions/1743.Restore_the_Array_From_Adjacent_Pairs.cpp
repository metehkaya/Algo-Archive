class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        int n = adj.size();
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ ) {
            int x = adj[i][0];
            int y = adj[i][1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        int curr;
        for(auto it : mp)
            if(it.second.size() == 1)
                curr = it.first;
        set<int> s;
        vector<int> ans;
        s.insert(curr);
        ans.push_back(curr);
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> v = mp[curr];
            int sz = v.size();
            for( int j = 0 ; j < sz ; j++ ) {
                int nxt = v[j];
                if(s.find(nxt) == s.end()) {
                    curr = nxt;
                    break;
                }
            }
            s.insert(curr);
            ans.push_back(curr);
        }
        return ans;
    }
};