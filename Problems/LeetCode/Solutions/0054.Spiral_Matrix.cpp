class Solution {
public:
    const int DIR[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralOrder(vector<vector<int>>& ar) {
        vector<int> ans;
        int n = ar.size();
        if(n == 0)
            return ans;
        int m = ar[0].size();
        if(m == 0)
            return ans;
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        int i=0,j=0,cnt=1,curr=0;
        ans.push_back(ar[i][j]);
        mark[0][0] = true;
        while(cnt < n*m) {
            int x,y;
            bool firstTry = true;
            do {
                if(!firstTry)
                    curr = (curr+1) % 4;
                x = i+DIR[curr][0];
                y = j+DIR[curr][1];
                firstTry = false;
            }while(x<0 || x>=n || y<0 || y>=m || mark[x][y]);
            cnt++;
            i=x,j=y;
            mark[i][j] = true;
            ans.push_back(ar[i][j]);
        }
        return ans;
    }
};