class Solution {
public:
    vector<long long> getDistances(vector<int>& ar) {
        int n = ar.size();
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]].push_back(i);
        vector<long long> ans(n);
        for(auto it : mp) {
            vector<int> v = it.second;
            int sz = v.size();
            long long cost = 0;
            for( int i = 1 ; i < sz ; i++ )
                cost += v[i]-v[0];
            ans[v[0]] = cost;
            for( int i = 1 ; i < sz ; i++ ) {
                cost += (long long) i * (v[i]-v[i-1]);
                cost -= (long long) (sz-i) * (v[i]-v[i-1]);
                ans[v[i]] = cost;
            }
        }
        return ans;
    }
};
