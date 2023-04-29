class Solution {
public:
    long long minimumPerimeter(long long x) {
        long long n = 1;
        while(2*n*(n+1)*(2*n+1) < x)
            n++;
        return 8*n;
    }
};