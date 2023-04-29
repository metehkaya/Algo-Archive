class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '0') {
                if(mp.find(0) == mp.end())
                    mp[0] = {i,i};
            }
            else {
                int val = 0;
                for( int j = 0 ; j < min(n-i,30) ; j++ ) {
                    val = 2*val;
                    val += (s[i+j]-'0');
                    if(mp.find(val) == mp.end())
                        mp[val] = {i,i+j};
                }
            }
        }
        vector<vector<int>> ans;
        for(auto q : queries) {
            int x = (q[0] ^ q[1]);
            auto it = mp.find(x);
            if(it != mp.end())
                ans.push_back(it->second);
            else
                ans.push_back({-1,-1});
        }
        return ans;
    }
};
