typedef long long LL;

class Solution {
public:
    vector<bool> canEat(vector<int>& ar, vector<vector<int>>& q) {
        int n = ar.size();
        int m = q.size();
        vector<LL> sum;
        sum.push_back(0);
        for( int i = 0 ; i < n-1 ; i++ )
            sum.push_back(sum[i]+ar[i]);
        vector<bool> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int type = q[i][0];
            int day = q[i][1];
            int lim = q[i][2];
            LL mx = sum[type]+ar[type]-1;
            LL mn = sum[type]/lim;
            ans.push_back(mn <= day && day <= mx);
        }
        return ans;
    }
};