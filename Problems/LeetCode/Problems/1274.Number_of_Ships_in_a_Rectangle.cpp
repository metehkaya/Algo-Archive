class Sea {
public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};

class Solution {
public:
    vector<int> getVec(int x, int y) {
        vector<int> v(2);
        v[0] = x;
        v[1] = y;
        return v;
    }
    int countShips(Sea& sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = bottomLeft[0];
        int y1 = bottomLeft[1];
        int x2 = topRight[0];
        int y2 = topRight[1];
        if(!sea.hasShips(topRight,bottomLeft))
            return 0;
        if(topRight == bottomLeft)
            return 1;
        int sum = 0;
        int x = (x1 + x2) / 2;
        int y = (y1 + y2) / 2;
        if(x < x2 && y < y2) {
            sum += countShips(sea, getVec(x,y), getVec(x1,y1));
            sum += countShips(sea, getVec(x2,y), getVec(x+1,y1));
            sum += countShips(sea, getVec(x,y2), getVec(x1,y+1));
            sum += countShips(sea, getVec(x2,y2), getVec(x+1,y+1));
        }
        else if(x < x2) {
            sum += countShips(sea, getVec(x,y1), getVec(x1,y1));
            sum += countShips(sea, getVec(x2,y1), getVec(x+1,y1));
        }
        else {
            sum += countShips(sea, getVec(x1,y), getVec(x1,y1));
            sum += countShips(sea, getVec(x1,y2), getVec(x1,y+1));
        }
        return sum;
    }
};