class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<int> onesRow(n,0);
        vector<int> onesCol(m,0);
        vector<int> zerosRow(n,0);
        vector<int> zerosCol(m,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 0)
                    zerosRow[i]++ , zerosCol[j]++;
                else if(ar[i][j] == 1)
                    onesRow[i]++ , onesCol[j]++;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                ans[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
        return ans;
    }
};
