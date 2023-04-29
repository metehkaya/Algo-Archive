class Solution {
public:
    vector<int> xorQueries(vector<int>& ar, vector<vector<int>>& q) {
        int n = (int) ar.size();
        int m = (int) q.size();
        vector<int> xorPrefix(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            xorPrefix[i+1] = (xorPrefix[i] ^ ar[i]);
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int l = q[i][0];
            int r = q[i][1];
            ans.push_back(xorPrefix[l]^xorPrefix[r+1]);
        }
        return ans;
    }
};