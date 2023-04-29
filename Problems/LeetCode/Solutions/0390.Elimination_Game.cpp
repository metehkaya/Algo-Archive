class Solution {
public:
    int f(int n) {
        if(n == 1)
            return 0;
        if(n == 2 or n == 3)
            return 1;
        return (n%4 < 2) ? 1+4*f(n/4) : 3+4*f(n/4);
    }
    int lastRemaining(int n) {
        return f(n)+1;
    }
};
