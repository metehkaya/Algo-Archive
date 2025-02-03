class Solution {
public:
    int smallestNumber(int n) {
        for( int i = 9 ; i >= 0 ; i-- )
            if(n & (1 << i))
                return (1 << (i+1)) - 1;
        return -1;
    }
};