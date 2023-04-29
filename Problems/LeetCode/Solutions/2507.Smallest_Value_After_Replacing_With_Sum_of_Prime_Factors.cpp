class Solution {
public:
    int smallestValue(int n) {
        int prev = 0;
        while(prev != n) {
            prev = n;
            int sum = 0;
            for( int i = 2 ; i*i <= prev ; i++ )
                while(n % i == 0) {
                    sum += i;
                    n /= i;
                }
            if(n > 1)
                sum += n;
            n = sum;
        }
        return n;
    }
};
