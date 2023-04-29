typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4] = {0,1,0,-1};
    void dfs(int r , int c , vector<vector<int>>& ar , vector<vector<bool>>& mark , vector<pi>& v, int n , int m)  {
        mark[r][c] = true;
        v.push_back(pi(r,c));
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + DIR[i];
            int y = c + DIR[i^1];
            if(x == -1 or x == n or y == -1 or y == m or !ar[x][y])
                continue;
            if(!mark[x][y])
                dfs(x,y,ar,mark,v,n,m);
        }
    }
    int count(vector<pi>& v , vector<vector<bool>>& mark , int n , int m) {
        int ans = 4*v.size();
        for( int i = 0 ; i < v.size() ; i++ ) {
            int r = v[i].first;
            int c = v[i].second;
            for( int j = 0 ; j < 4 ; j++ ) {
                int x = r + DIR[j];
                int y = c + DIR[j^1];
                if(x == -1 or x == n or y == -1 or y == m)
                    continue;
                ans -= mark[x][y];
            }
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& ar) {
        int n = ar.size() , m = ar[0].size();
        int ans = 0;
        vector<pi> v;
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    dfs(i,j,ar,mark,v,n,m);
                    return count(v,mark,n,m);
                }
        return -1;
    }
};