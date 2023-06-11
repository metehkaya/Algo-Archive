class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long ans = 0;
        int m = q.size();
        set<int> row,col;
        for( int i = m-1 ; i >= 0 ; i-- )
            if(q[i][0] == 0) {
                if(row.find(q[i][1]) != row.end())
                    continue;
                row.insert(q[i][1]);
                ans += (long long) q[i][2] * (n - col.size());
            }
            else {
                if(col.find(q[i][1]) != col.end())
                    continue;
                col.insert(q[i][1]);
                ans += (long long) q[i][2] * (n - row.size());
            }
        return ans;
    }
};
