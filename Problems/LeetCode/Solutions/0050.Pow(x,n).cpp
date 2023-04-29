class Solution {
public:
    double f(double x , int n) {
        if(n == 0)
            return 1;
        double res = f(x,n/2);
        res = res*res;
        if(n & 1)
            res *= x;
        return res;
    }
    double myPow(double x, int n) {
        double mult = 1;
        if(n < 0) {
            x = 1/x;
            if(n == INT_MIN) {
                n = INT_MAX;
                mult = x;
            }
            else
                n = -n;
        }
        return f(x,n)*mult;
    }
};