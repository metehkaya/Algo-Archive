class SnakeGame {
public:
    int n,m,r,c,idx;
    deque<vector<int>> q;
    unordered_set<int> s;
    vector<vector<int>> food;
    SnakeGame(int m, int n, vector<vector<int>>& food) {
        r = c = idx = 0;
        this->n = n;
        this->m = m;
        this->food = food;
        q.push_front({r,c});
        s.insert(m*r+c);
    }
    int move(string dir) {
        if(dir == "U")
            r--;
        else if(dir == "D")
            r++;
        else if(dir == "L")
            c--;
        else if(dir == "R")
            c++;
        if(r < 0 or r >= n or c < 0 or c >= m)
            return -1;
        if(idx < food.size() and r == food[idx][0] and c == food[idx][1])
            idx++;
        else {
            auto v = q.back();
            q.pop_back();
            s.erase(m*v[0]+v[1]);
        }
        if(s.count(m*r+c))
            return -1;
        s.insert(m*r+c);
        q.push_front({r,c});
        return idx;
    }
};
