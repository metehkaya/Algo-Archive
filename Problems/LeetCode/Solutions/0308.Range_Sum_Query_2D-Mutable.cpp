class NumMatrix {
public:
    int n,m;
    vector<vector<int>> ar;
    vector<vector<int>> tree;
    NumMatrix(vector<vector<int>>& mat) {
        ar = mat;
        n = ar.size();
        if(n)
            m = ar[0].size();
        else
            m = 0;
        tree.resize(n+1,vector<int>(m+1,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                updateTree(i+1,j+1,ar[i][j]);
    }
    void updateTree(int r , int c , int val) {
        while(r <= n) {
            int i = c;
            while(i <= m) {
                tree[r][i] += val;
                i += (i & (-i));
            }
            r += (r & (-r));
        }
    }
    void update(int row, int col, int val) {
        int diff = val - ar[row][col];
        ar[row][col] = val;
        updateTree(row+1,col+1,diff);
    }
    int queryTree(int r , int c) {
        int sum = 0;
        while(r) {
            int i = c;
            while(i) {
                sum += tree[r][i];
                i -= (i & (-i));
            }
            r -= (r & (-r));
        }
        return sum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        ans += queryTree(row2+1,col2+1);
        ans -= queryTree(row1,col2+1);
        ans -= queryTree(row2+1,col1);
        ans += queryTree(row1,col1);
        return ans;
    }
};