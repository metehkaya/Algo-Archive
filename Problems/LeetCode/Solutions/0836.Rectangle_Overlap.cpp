class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int leftX = max(rec1[0], rec2[0]);
        int rightX = min(rec1[2], rec2[2]);
        int bottomY = max(rec1[1], rec2[1]);
        int topY = min(rec1[3], rec2[3]);
        if( leftX >= rightX || bottomY >= topY )
            return false;
        return true;
    }
};