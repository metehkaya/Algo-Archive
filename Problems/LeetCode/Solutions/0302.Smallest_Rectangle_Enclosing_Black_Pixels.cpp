class Solution {
public:
    int n,m;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    void dfs(int x , int y , int& xmn , int& xmx , int& ymn , int& ymx , vector<vector<char>>& ar) {
        ar[x][y] = '0';
        xmn = min(xmn,x);
        xmx = max(xmx,x);
        ymn = min(ymn,y);
        ymx = max(ymx,y);
        for( int i = 0 ; i < 4 ; i++ ) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && ar[x2][y2] == '1')
                dfs(x2,y2,xmn,xmx,ymn,ymx,ar);
        }
    }
    int minArea(vector<vector<char>>& ar, int x, int y) {
        n = ar.size();
        m = ar[0].size();
        int xmn = x , xmx = x;
        int ymn = y , ymx = y;
        dfs(x,y,xmn,xmx,ymn,ymx,ar);
        return (xmx-xmn+1)*(ymx-ymn+1);
    }
};