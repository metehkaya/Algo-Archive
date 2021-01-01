class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        int n = 2;
        while(true) {
            int z = fib[n-1] + fib[n-2];
            if(z > k)
                break;
            n++;
            fib.push_back(z);
        }
        int ans = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int add = k / fib[i];
            ans += add;
            k -= add * fib[i];
        }
        return ans;
    }
};