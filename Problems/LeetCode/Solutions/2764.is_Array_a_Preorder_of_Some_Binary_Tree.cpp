class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
        int n = nodes.size();
        if(nodes[0][1] != -1)
            return false;
        unordered_map<int,int> mp;
        vector<int> chain;
        chain.push_back(nodes[0][0]);
        mp[nodes[0][0]] = 0;
        for( int i = 1 ; i < n ; i++ ) {
            if(nodes[i][1] != nodes[i-1][0]) {
                if(mp.count(nodes[i][1]) == 0)
                    return false;
                while(chain.back() != nodes[i][1]) {
                    int u = chain.back();
                    chain.pop_back();
                    mp.erase(u);
                }
            }
            mp[nodes[i][0]] = (int) chain.size();
            chain.push_back(nodes[i][0]);
        }
        return true;
    }
};
