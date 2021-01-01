class Robot {
public:
    bool move();
    void turnLeft();
    void turnRight();
    void clean();
};

typedef pair<int,int> pi;

class Solution {
public:
    int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
    void dfs(int r , int c , int way , set<pi>& mark , Robot& robot) {
        robot.clean();
        for( int i = 0 ; i < 4 ; i++ ) {
            int x = r + dir[way][0];
            int y = c + dir[way][1];
            if(mark.find(pi(x,y)) == mark.end()) {
                mark.insert(pi(x,y));
                if(robot.move()) {
                    dfs(x,y,way,mark,robot);
                    robot.turnRight();
                    robot.turnRight();
                }
            }
            robot.turnRight();
            way = (way+1) % 4;
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
    }
    void cleanRoom(Robot& robot) {
        set<pi> mark;
        mark.insert(pi(0,0));
        dfs(0,0,0,mark,robot);
    }
};