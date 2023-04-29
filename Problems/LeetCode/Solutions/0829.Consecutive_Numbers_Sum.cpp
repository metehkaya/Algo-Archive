class Solution {
public:
    int consecutiveNumbersSum(int n) {
        n *= 2;
        int ans = 0;
        for( int i = 1 ; i*i <= n ; i++ ) {
            if(n % i)
                continue;
            int x = n/i - i + 1;
            if(x < 0 || x % 2)
                continue;
            ans++;
        }
        return ans;
    }
};