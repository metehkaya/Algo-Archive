class Solution {
public:
    const int DIR[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        if(n == 0)
            return ans;
        int i=0,j=0,cnt=0,curr=0;
        ans[i][j] = ++cnt;
        while(cnt < n*n) {
            int x,y;
            bool firstTry = true;
            do {
                if(!firstTry)
                    curr = (curr+1) % 4;
                x = i+DIR[curr][0];
                y = j+DIR[curr][1];
                firstTry = false;
            }while(x<0 || x>=n || y<0 || y>=n || ans[x][y] != 0);
            ans[i=x][j=y] = ++cnt;
        }
        return ans;
    }
};