class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx-fx);
        int y = abs(sy-fy);
        int mn = max(x,y);
        if(t < mn)
            return false;
        if(sx == fx and sy == fy and t == 1)
            return false;
        return true;
    }
};
