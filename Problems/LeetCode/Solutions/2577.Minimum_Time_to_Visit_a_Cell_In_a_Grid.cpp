class Solution {
public:
    int dir[4] = {0,1,0,-1};
    int minimumTime(vector<vector<int>>& v) {
        if(min(v[0][1],v[1][0]) > 1)
            return -1;
        int n = v.size() , m = v[0].size();
        vector<vector<int>> d(n,vector<int>(m,-1));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        d[0][0] = 0;
        heap.push({0,0,0});
        while(!heap.empty()) {
            auto temp = heap.top();
            heap.pop();
            int dist = temp[0] , r = temp[1] , c = temp[2];
            if(r == n-1 and c == m-1)
                return dist;
            if(dist > d[r][c])
                continue;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i];
                int y = c+dir[i^1];
                if(x < 0 or y < 0 or x >= n or y >= m)
                    continue;
                int dist_new = max(dist,v[x][y]);
                if(dist_new % 2 == dist % 2)
                    dist_new++;
                if(d[x][y] == -1 or dist_new < d[x][y]) {
                    d[x][y] = dist_new;
                    heap.push({dist_new,x,y});
                }
            }
        }
        return -1;
    }
};
