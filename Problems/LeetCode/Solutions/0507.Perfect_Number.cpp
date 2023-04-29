class Solution {
public:
    bool checkPerfectNumber(int n) {
        if(n == 1)
            return false;
        int sum = 0;
        for( int i = 1 ; i*i <= n ; i++ )
            if(n % i == 0) {
                sum += i;
                int j = n/i;
                if(i != j && i != 1)
                    sum += j;
            }
        return sum == n;
    }
};