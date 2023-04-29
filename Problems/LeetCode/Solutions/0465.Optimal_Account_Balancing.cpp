class Solution {
public:
    int n;
    int f(int id , vector<int>& v) {
        if(id == v.size())
            return 0;
        if(v[id] == 0)
            return f(id+1,v);
        int ans = INT_MAX;
        for( int i = id+1 ; i < n ; i++ )
            if(v[id] * v[i] < 0) {
                v[i] += v[id];
                ans = min(ans,f(id+1,v)+1);
                v[i] -= v[id];
            }
        return ans;
    }
    int minTransfers(vector<vector<int>>& ar) {
        int m = ar.size();
        map<int,int> mp;
        for( int i = 0 ; i < m ; i++ ) {
            mp[ar[i][0]] += ar[i][2];
            mp[ar[i][1]] -= ar[i][2];
        }
        vector<int> v;
        for(auto it : mp)
            if(it.second)
                v.push_back(it.second);
        n = v.size();
        return f(0,v);
    }
};
