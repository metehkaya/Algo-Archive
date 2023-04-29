class Solution {
public:
    int distMoney(int m, int c) {
        if(m < c or (c == 1 and m == 4))
            return -1;
        m -= c;
        if(m <= 7*c) {
            int p = m/7;
            int q = m%7;
            return q == 3 and p == c-1 ? max(p-1,0) : p;
        }
        else
            return c-1;
    }
};
