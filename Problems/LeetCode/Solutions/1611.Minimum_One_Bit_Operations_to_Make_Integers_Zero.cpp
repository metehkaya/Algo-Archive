class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1)
            return n;
        int k = 0;
        while((1<<k) <= n)
            k++;
        return ((1<<k)-1) - minimumOneBitOperations(n-(1<<(k-1)));
    }
};
