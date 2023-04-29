class Solution {
public:
    int n,m;
    static const int maxv = 101;
    static const int maxn = 100001;
    int cnt[maxn][maxv];
    vector<int> minDifference(vector<int>& ar, vector<vector<int>>& q) {
        n = ar.size();
        m = q.size();
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= 100 ; j++ )
                cnt[i][j] = cnt[i-1][j] + (ar[i-1] == j);
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int l = q[i][0];
            int r = q[i][1]+1;
            vector<int> v;
            for( int j = 1 ; j <= 100 ; j++ )
                if(cnt[r][j] > cnt[l][j])
                    v.push_back(j);
            int sz = v.size();
            if(sz == 1)
                ans.push_back(-1);
            else {
                int res = INT_MAX;
                for( int j = 1 ; j < sz ; j++ )
                    res = min(res,v[j]-v[j-1]);
                ans.push_back(res);
            }
        }
        return ans;
    }
};