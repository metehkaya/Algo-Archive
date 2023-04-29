typedef vector<char> vc;
typedef vector<vc> vcc;
typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4][2] = {{0,-1},{0,+1},{-1,0},{+1,0}};
    void dfs(int r , int c , bool& ok , vcc& ar , vector<pi>& v) {
        ar[r][c] = '-';
        v.push_back(pi(r,c));
        if(r == 0 || r == ar.size()-1 || c == 0 || c == ar[0].size()-1)
            ok = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + DIR[i][0];
            int y = c + DIR[i][1];
            if(x < 0 || x >= ar.size() || y < 0 || y >= ar[0].size())
                continue;
            if(ar[x][y] != 'O')
                continue;
            dfs(x,y,ok,ar,v);
        }
    }
    void solve(vcc& ar) {
        int n = ar.size();
        if(n == 0)
            return;
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if( ar[i][j] == 'O' ) {
                    vector<pi> v;
                    bool ok = false;
                    dfs(i,j,ok,ar,v);
                    if(!ok)
                        for( int k = 0 ; k < v.size() ; k++ )
                            ar[v[k].first][v[k].second] = 'X';
                }
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == '-')
                    ar[i][j] = 'O';
    }
};