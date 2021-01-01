class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& ar) {
        vector<int> ans;
        int n = ar.size();
        if(n == 0)
            return ans;
        int m = ar[0].size();
        if(m == 0)
            return ans;
        for( int d = 0 ; d <= n-1+m-1 ; d++ ) {
            vector<int> add;
            for( int i = 0 ; i < n ; i++ ) {
                int j = d-i;
                if(j >= 0 && j < m)
                    add.push_back(i);
            }
            if(d%2 == 0)
                reverse(add.begin(),add.end());
            int sz = add.size();
            for( int i = 0 ; i < sz ; i++ )
                ans.push_back(ar[add[i]][d-add[i]]);
        }
        return ans;
    }
};