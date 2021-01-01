class Solution {
public:
    int f(int num , int bm , int n) {
        int res = 0;
        if(num <= n)
            res++;
        if(num*10LL > n)
            return res;
        for( int i = 0 ; i < 10 ; i++ ) {
            if(!num && !i)
                continue;
            if(bm & (1<<i))
                continue;
            res += f(10*num+i , bm | (1<<i) , n);
        }
        return res;
    }
    int numDupDigitsAtMostN(int n) {
        return (n+1) - f(0,0,n);
    }
};