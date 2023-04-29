class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& ar, vector<vector<int>>& dig) {
        vector<vector<bool>> mark(n,vector<bool>(n,false));
        for( int i = 0 ; i < dig.size() ; i++ )
            mark[dig[i][0]][dig[i][1]] = true;
        int ans = 0;
        for( int i = 0 ; i < ar.size() ; i++ ) {
            bool add = true;
            for( int r = ar[i][0] ; r <= ar[i][2] ; r++ )
                for( int c = ar[i][1] ; c <= ar[i][3] ; c++ )
                    if(!mark[r][c])
                        add = false;
            ans += add;
        }
        return ans;
    }
};
