class Solution {
public:
    double angleClock(int h, int m) {
        h %= 12;
        double deg1 = m*6;
        double deg2 = h*30 + m/2.0;
        if(deg1 > deg2)
            swap(deg1, deg2);
        return min( deg2-deg1 , 360-(deg2-deg1) );
    }
};