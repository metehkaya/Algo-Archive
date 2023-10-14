class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;
        int sum = k*(k+1)/2 * m;
        int sum_all = n*(n+1)/2;
        return sum_all - 2*sum;
    }
};
