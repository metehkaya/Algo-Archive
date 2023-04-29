class Solution {
public:
    static const int maxn = 100;
    bool mark[maxn][maxn];
    const int dir[4] = {0,1,0,-1};
    const string DIR = "rdlu";
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int n = maze.size() , m = maze[0].size();
        auto comp = [&](const tuple<int, int, int, string>& a,
                        const tuple<int, int, int, string>& b) { 
            if(get<0>(a) != get<0>(b))
                return get<0>(a) > get<0>(b);
            return get<3>(a) > get<3>(b);
        };
        priority_queue<tuple<int, int, int, string>, 
            vector<tuple<int, int, int, string>>,
            decltype(comp)> pq(comp);
        pq.push({0,ball[0], ball[1], ""});
        while(!pq.empty()) {
            auto [dist, r, c, path] = pq.top();
            pq.pop();
            if(r == hole[0] and c == hole[1])
                return path;
            if(mark[r][c])
                continue;
            mark[r][c] = true;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+dir[i] , y = c+dir[i^1] , new_dist = dist+1;
                string new_path = path+DIR[i];
                bool found = false;
                while(x >= 0 and x < n and y >= 0 and y < m and !maze[x][y] and !found) {
                    if(x == hole[0] and y == hole[1])
                        found = true;
                    else
                        x += dir[i] , y += dir[i^1] , new_dist++;
                }
                if(!found)
                    x -= dir[i] , y -= dir[i^1] , new_dist--;
                if(!mark[x][y])
                    pq.emplace(make_tuple(new_dist,x,y,new_path));
            }
        }
        return "impossible";
    }
};
