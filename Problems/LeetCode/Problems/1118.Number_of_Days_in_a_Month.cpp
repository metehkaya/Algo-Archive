class Solution {
public:
    const int DAY[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int numberOfDays(int y, int m) {
        m--;
        if(m == 1)
            if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
                return 29;
        return DAY[m];
    }
};