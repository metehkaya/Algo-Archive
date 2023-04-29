class Solution {
public:
    void f(int& n , int x) {
        while(n%x == 0)
            n /= x;
    }
    bool isUgly(int n) {
        if(n == 0)
            return false;
        f(n,2);
        f(n,3);
        f(n,5);
        return n==1;
    }
};