typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef vector<vb> vbb;

class Solution {
public:
    void f(vi curr , int dx , int dy , vbb& mark , vii& ans ) {
        if(min(curr[0],curr[1]) == -1)
            return;
        if(max(curr[0],curr[1]) == 8)
            return;
        if(mark[curr[0]][curr[1]]) {
            ans.push_back(curr);
            return;
        }
        curr[0] += dx;
        curr[1] += dy;
        f(curr,dx,dy,mark,ans);
    }
    vii queensAttacktheKing(vii& queens, vi& king) {
        vbb mark(8,vb(8,0));
        int n = queens.size();
        for( int i = 0 ; i < n ; i++ ) {
            int r = queens[i][0];
            int c = queens[i][1];
            mark[r][c] = true;
        }
        vii ans;
        for( int i = -1 ; i <= 1 ; i++ )
            for( int j = -1 ; j <= 1 ; j++ )
                if(i or j)
                    f(king,i,j,mark,ans);
        return ans;
    }
};