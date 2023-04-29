class Solution {
public:
    vector<int> f(int num) {
        int sq = sqrt(num);
        vector<int> res(2);
        for( int i = sq ; i >= 1 ; i-- )
            if( num % i == 0 ) {
                res[0] = i;
                res[1] = num/i;
                break;
            }
        return res;
    }
    vector<int> closestDivisors(int num) {
        vector<int> a = f(num+1);
        vector<int> b = f(num+2);
        if(a[1]-a[0] < b[1]-b[0])
            return a;
        return b;
    }
};