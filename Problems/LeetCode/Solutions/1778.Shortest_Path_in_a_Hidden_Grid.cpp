class Solution {
public:
    int dir[4] = {0,1,0,-1};
    string dirs = "RDLU";
    static const int source = 500;
    static const int maxn = 2*source+1;
    bool mark[maxn][maxn];
    bool empty[maxn][maxn];
    int dist[maxn][maxn];
    int target_r=-1 , target_c=-1;
    void dfs(int r , int c , GridMaster &master) {
        if(master.isTarget()) {
            target_r = r;
            target_c = c;
        }
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i] , y = c + dir[i^1];
            if(!mark[x][y]) {
                bool can_move = master.canMove(dirs[i]);
                mark[x][y] = true;
                if(can_move) {
                    empty[x][y] = true;
                    master.move(dirs[i]);
                    dfs(x,y,master);
                    master.move(dirs[(i+2)%4]);
                }
            }
        }
    }
    int findShortestPath(GridMaster &master) {
        memset(mark,false,sizeof(mark));
        memset(empty,false,sizeof(empty));
        mark[source][source] = true;
        empty[source][source] = true;
        dfs(source,source,master);
        if(target_r == -1)
            return -1;
        memset(dist,-1,sizeof(dist));
        queue<vector<int>> q;
        q.push({source,source});
        dist[source][source] = 0;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int r = v[0] , c = v[1];
            if(r == target_r and c == target_c)
                return dist[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i] , y = c + dir[i^1];
                if(empty[x][y] and dist[x][y] == -1) {
                    q.push({x,y});
                    dist[x][y] = dist[r][c] + 1;
                }
            }
        }
        return -1;
    }
};
