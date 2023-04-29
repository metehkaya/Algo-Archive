class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrixIII(int n, int m, int r, int c) {
        vector<vector<int>> ans;
        ans.push_back({r,c});
        int nVisited = 1 , rMin = r , rMax = r , cMin = c , cMax = c , d = 0;
        while(nVisited < n*m) {
            r += dir[d][0];
            c += dir[d][1];
            if(0 <= r and r < n and 0 <= c and c < m)
                nVisited++ , ans.push_back({r,c});
            if(d == 0 and c > cMax)
                cMax++ , d = 1;
            else if(d == 1 and r > rMax)
                rMax++ , d = 2;
            else if(d == 2 and c < cMin)
                cMin-- , d = 3;
            else if(d == 3 and r < rMin)
                rMin-- , d = 0;
        }
        return ans;
    }
};
