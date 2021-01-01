typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution {
public:
    bool ans = false;
    int dir[4] = {0,1,0,-1};
    void dfs(int r , int c , int x , int y , int d , vii& ar , viii& mark) {
        if(mark[r][c][d])
            return;
        mark[r][c][d] = 1;
        int R = r + dir[d] , C = c + dir[d^1];
        bool ch = false;
        if(R < 0 || R >= ar.size() || C < 0 || C >= ar[0].size() || ar[R][C])
            ch = true;
        if(r == x && c == y && ch)
            ans = true;
        if(!ch)
            dfs(R,C,x,y,d,ar,mark);
        else
            for( int i = 0 ; i < 4 ; i++ )
                dfs(r,c,x,y,i,ar,mark);
    }
    bool hasPath(vii& ar, vi& src, vi& dest) {
        int n = ar.size() , m = ar[0].size();
        viii mark(n,vii(m,vi(4,0)));
        for( int i = 0 ; i < 4 ; i++ )
            dfs(src[0],src[1],dest[0],dest[1],i,ar,mark);
        return ans;
    }
};