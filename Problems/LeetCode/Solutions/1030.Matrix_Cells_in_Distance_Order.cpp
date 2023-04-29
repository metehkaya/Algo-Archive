class Solution {
public:
    const int DIR[4][2] = {{0,+1},{+1,0},{0,-1},{-1,0}};
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        vector<vector<bool>> mark(R,vector<bool>(C,false));
        vector<int> curr(2);
        curr[0] = r0 , curr[1] = c0;
        mark[r0][c0] = true;
        queue<vector<int>> Q;
        Q.push(curr);
        while(!Q.empty()) {
            curr = Q.front();
            Q.pop();
            ans.push_back(curr);
            for( int i = 0 ; i < 4 ; i++ ) {
                vector<int> temp(2);
                temp[0] = curr[0] + DIR[i][0];
                temp[1] = curr[1] + DIR[i][1];
                if(temp[0] < 0 || temp[0] == R || temp[1] < 0 || temp[1] == C)
                    continue;
                if(mark[temp[0]][temp[1]])
                    continue;
                Q.push(temp);
                mark[temp[0]][temp[1]] = true;
            }
        }
        return ans;
    }
};