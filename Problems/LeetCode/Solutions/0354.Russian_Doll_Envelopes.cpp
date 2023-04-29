class Solution {
public:
    static const int maxv = 100001;
    int dp[maxv];
    void update(int idx , int val) {
        while(idx < maxv) {
            dp[idx] = max(dp[idx],val);
            idx += (idx & (-idx));
        }
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res = max(res,dp[idx]);
            idx -= (idx & (-idx));
        }
        return res;
    }
    int maxEnvelopes(vector<vector<int>>& ar) {
        int ans = 0;
        int n = ar.size();
        sort(ar.begin(),ar.end());
        memset(dp,0,sizeof(maxv));
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            vector<int> res;
            while(j < n && ar[i][0] == ar[j][0]) {
                res.push_back(query(ar[j][1]-1)+1);
                j++;
            }
            for( int k = 0 ; k < j-i ; k++ ) {
                ans = max(ans,res[k]);
                update(ar[i+k][1],res[k]);
            }
        }
        return ans;
    }
};
