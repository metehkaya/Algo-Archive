class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int m = queries.size();
        vector<int> indices;
        int cnt = 0;
        int sum[n];
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '|') {
                cnt++;
                indices.push_back(i);
            }
            sum[i] = cnt;
        }
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int left = queries[i][0];
            int right = queries[i][1];
            vector<int>::iterator l = lower_bound(indices.begin(), indices.end(), left);
            vector<int>::iterator r = upper_bound(indices.begin(), indices.end(), right);
            if(l == indices.end() || r == indices.begin()) {
                ans.push_back(0);
                continue;
            }
            r--;
            int li = (*l);
            int ri = (*r);
            if(li > ri || li > right || ri < left) {
                ans.push_back(0);
                continue;
            }
            int c0 = ri-li+1;
            int c1 = sum[ri] - ((li == 0) ? 0 : sum[li-1]);
            ans.push_back(c0-c1);
        }
        return ans;
    }
};
