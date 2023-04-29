class Solution {
public:
    bool check(int xc, int yc, int r, int x, int y) {
        return (x-xc)*(x-xc) + (y-yc)*(y-yc) <= r*r;
    }
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        bool ans = false;
        ans |= check(xc, yc, r, x1, y1);
        ans |= check(xc, yc, r, x1, y2);
        ans |= check(xc, yc, r, x2, y1);
        ans |= check(xc, yc, r, x2, y2);
        ans |= xc >= x2 && yc >= y1 && yc <= y2 && xc-x2 <= r;
        ans |= xc <= x1 && yc >= y1 && yc <= y2 && x1-xc <= r;
        ans |= yc >= y2 && xc >= x1 && xc <= x2 && yc-y2 <= r;
        ans |= yc <= y1 && xc >= x1 && xc <= x2 && y1-yc <= r;
        ans |= xc >= x1 && xc <= x2 && yc >= y1 && yc <= y2;
        return ans;
    }
};