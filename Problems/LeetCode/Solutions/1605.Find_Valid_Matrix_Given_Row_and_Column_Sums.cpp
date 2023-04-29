#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vi& rowSum, vi& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vii ans(n,vi(m,0));
        vector<pi> rows,cols;
        for( int i = 0 ; i < n ; i++ )
            rows.pb(pi(rowSum[i],i));
        for( int i = 0 ; i < m ; i++ )
            cols.pb(pi(colSum[i],i));
        int i = 0 , j = 0;
        while(i < n && j < m) {
            while(i < n && rows[i].fi == 0)
                i++;
            while(j < m && cols[j].fi == 0)
                j++;
            if(i == n || j == m)
                break;
            int mn = min(rows[i].fi,cols[j].fi);
            rows[i].fi -= mn;
            cols[j].fi -= mn;
            int a = rows[i].se;
            int b = cols[j].se;
            ans[a][b] = mn;
        }
        return ans;
    }
};
