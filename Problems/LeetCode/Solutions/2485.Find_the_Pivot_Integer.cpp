class Solution {
public:
    int pivotInteger(int n) {
        int x = sqrt((n*n+n)/2);
        return (2*x*x == n*n+n) ? x : -1;
    }
};
