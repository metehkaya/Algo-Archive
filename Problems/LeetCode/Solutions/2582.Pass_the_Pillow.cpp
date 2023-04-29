class Solution {
public:
    int passThePillow(int n, int t) {
        int loop = (n-1);
        int rem = t % (2*loop);
        return (rem < loop) ? 1+rem : n-(rem-loop);
    }
};
