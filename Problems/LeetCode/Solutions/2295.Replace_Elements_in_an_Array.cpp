class Solution {
public:
    vector<int> arrayChange(vector<int>& ar, vector<vector<int>>& ops) {
        int n = ar.size() , m = ops.size();
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]] = i;
        for( int i = 0 ; i < m ; i++ ) {
            int x = ops[i][0];
            int y = ops[i][1];
            int idx = mp[x];
            mp.erase(x);
            ar[idx] = y;
            mp[y] = idx;
        }
        return ar;
    }
};
