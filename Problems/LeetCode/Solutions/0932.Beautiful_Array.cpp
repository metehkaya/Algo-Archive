class Solution {
public:
    map<int,vector<int>> dp;
    vector<int> beautifulArray(int n) {
        if(n == 1) {
            vector<int> v(1,1);
            return v;
        }
        auto it = dp.find(n);
        if(it != dp.end())
            return it->second;
        vector<int> l = beautifulArray(n-n/2);
        vector<int> r = beautifulArray(n/2);
        vector<int> ans;
        for( int i = 0 ; i < l.size() ; i++ )
            ans.push_back(2*l[i]-1);
        for( int i = 0 ; i < r.size() ; i++ )
            ans.push_back(2*r[i]);
        return dp[n] = ans;
    }
};