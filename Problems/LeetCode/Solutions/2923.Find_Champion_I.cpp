class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            for(int x : grid[i])
                cnt += x;
            if(cnt == n-1)
                return i;
        }
        return -1;
    }
};
