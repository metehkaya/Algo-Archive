class Solution {
public:
    int dir[4] = {0,1,0,-1};
    string dirs = "RDLU";
    static const int source = 100;
    static const int maxn = 2*source+1;
    bool mark[maxn][maxn];
    bool empty[maxn][maxn];
    int dist[maxn][maxn];
    int edge[maxn][maxn][4];
    int target_r=-1 , target_c=-1;
    void dfs(int r , int c , GridMaster &master) {
        if(master.isTarget()) {
            target_r = r;
            target_c = c;
        }
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[i] , y = c + dir[i^1];
            bool can_move = master.canMove(dirs[i]);
            if(can_move) {
                empty[x][y] = true;
                edge[r][c][i] = master.move(dirs[i]);
                if(!mark[x][y]) {
                    mark[x][y] = true;
                    dfs(x,y,master);
                }
                master.move(dirs[(i+2)%4]);
            }
        }
    }
    int findShortestPath(GridMaster &master) {
        memset(mark,false,sizeof(mark));
        memset(empty,false,sizeof(empty));
        memset(edge,-1,sizeof(edge));
        mark[source][source] = true;
        empty[source][source] = true;
        dfs(source,source,master);
        if(target_r == -1)
            return -1;
        memset(dist,-1,sizeof(dist));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        heap.push({0,source,source});
        dist[source][source] = 0;
        while(!heap.empty()) {
            auto v = heap.top();
            heap.pop();
            int d = v[0] , r = v[1] , c = v[2];
            if(r == target_r and c == target_c)
                return dist[r][c];
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + dir[i] , y = c + dir[i^1];
                int d_new = d + edge[r][c][i];
                if(empty[x][y] and (dist[x][y] == -1 or d_new < dist[x][y])) {
                    heap.push({d_new,x,y});
                    dist[x][y] = d_new;
                }
            }
        }
        return -1;
    }
};
