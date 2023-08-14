class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& x, vector<int>& y, vector<vector<int>>& q) {
        int n = x.size() , m = q.size();
        vector<pair<pair<int,int>,int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(make_pair(make_pair(x[i],y[i]),i));
        sort(v.begin(),v.end());
        vector<pair<pair<int,int>,int>> q_sorted;
        for( int i = 0 ; i < m ; i++ )
            q_sorted.push_back(make_pair(make_pair(q[i][0],q[i][1]),i));
        sort(q_sorted.begin(),q_sorted.end());
        vector<int> y_sorted = y;
        sort(y_sorted.begin(),y_sorted.end());
        y_sorted.erase( unique(y_sorted.begin(),y_sorted.end()) , y_sorted.end() );
        int n_y = y_sorted.size();
        vector<int> tree(n_y+1,-1);
        vector<int> ans(m,-1);
        for( int j = m-1 , i = n-1 ; j >= 0 ; j-- ) {
            int q_idx = q_sorted[j].second;
            while(i >= 0 and v[i].first.first >= q_sorted[j].first.first) {
                int pos = lower_bound(y_sorted.begin(), y_sorted.end(), v[i].first.second) - y_sorted.begin() + 1;
                int val = v[i].first.first + v[i].first.second;
                while(pos > 0) {
                    tree[pos] = max(tree[pos],val);
                    pos -= (pos & (-pos));
                }
                i--;
            }
            int res = -1;
            int pos = lower_bound(y_sorted.begin(), y_sorted.end(), q_sorted[j].first.second) - y_sorted.begin() + 1;
            while(pos <= n_y) {
                res = max(res,tree[pos]);
                pos += (pos & (-pos));
            }
            ans[q_idx] = res;
        }
        return ans;
    }
};
