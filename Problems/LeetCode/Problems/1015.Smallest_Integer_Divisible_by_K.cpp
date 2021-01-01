class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 0;
        for( int i = 1 ; i <= k ; i++ ) {
            num = (10*num + 1) % k;
            if(num == 0)
                return i;
        }
        return -1;
    }
};