class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        set<int> idx_row_to_col[n] , idx_col_to_row[m];
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                idx_row_to_col[i].insert(j);
                idx_col_to_row[j].insert(i);
            }
        int ans[n][m];
        memset(ans,-1,sizeof(ans));
        ans[0][0] = 1;
        queue<vector<int>> q;
        q.push({0,0});
        idx_row_to_col[0].erase(0);
        idx_col_to_row[0].erase(0);
        while(!q.empty()) {
            auto idx = q.front();
            q.pop();
            int row = idx[0] , col = idx[1];
            set<int>::iterator it;
            while((it = idx_row_to_col[row].upper_bound(col)) != idx_row_to_col[row].end() and (*it) <= col+v[row][col]) {
                int other_col = (*it);
                q.push({row,other_col});
                ans[row][other_col] = ans[row][col]+1;
                idx_row_to_col[row].erase(other_col);
                idx_col_to_row[other_col].erase(row);
            }
            while((it = idx_col_to_row[col].upper_bound(row)) != idx_col_to_row[col].end() and (*it) <= row+v[row][col]) {
                int other_row = (*it);
                q.push({other_row,col});
                ans[other_row][col] = ans[row][col]+1;
                idx_col_to_row[col].erase(other_row);
                idx_row_to_col[other_row].erase(col);
            }
        }
        return ans[n-1][m-1];
    }
};
