class Solution {
public:
    int f(long long n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        if(f(n) <= target)
            return 0;
        for( int i = 1 ; true ; i++ ) {
            long long p10 = pow(10,i);
            long long add = p10 - n%p10;
            if(f(n+add) <= target)
                return add;
        }
        return -1;
    }
};
