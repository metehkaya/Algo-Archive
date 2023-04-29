class Solution {
public:
    int getSum(int a, int b) {
        int res;
        if(b == 0)
            res = a;
        else
            res = getSum(a^b,(unsigned int)(a&b)<<1);
        return res;
    }
};