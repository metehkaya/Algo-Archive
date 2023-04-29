class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& p, vector<vector<int>>& q) {
        int n = p.size();
        int m = q.size();
        vector<int> ans;
        for( int j = 0 ; j < m ; j++ ) {
            int cnt = 0;
            for( int i = 0 ; i < n ; i++ ) {
                int dx = p[i][0] - q[j][0];
                int dy = p[i][1] - q[j][1];
                int r = q[j][2];
                if(dx*dx + dy*dy <= r*r)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};