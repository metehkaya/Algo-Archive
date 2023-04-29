class Solution {
public:
    int fib(int N) {
        if(N <= 1)
            return N;
        int prev=0,last=1;
        for( int i = 2 ; i <= N ; i++ ) {
            int sum = prev+last;
            prev = last;
            last = sum;
        }
        return last;
    }
};